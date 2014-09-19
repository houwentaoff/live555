/*
****************************************************************************
*
** \file      bsreader2file.c
**
** \version   
**
** \brief     
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOFORTUNE SEMICONDUCTOR
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR 
**            OMMISSIONS.
**
** (C) Copyright 2012-2013 by GOKE MICROELECTRONICS CO.,LTD
**
****************************************************************************
*/

#include <stdlib.h>
#include "iav_drv.h"
#include "iav_drv_ex.h"
#include "bsreader.h"

int map_bsb(int fd_iav)
{
	iav_mmap_info_t info;
	static int mem_mapped = 0;

	if (mem_mapped)
		return 0;

	if (ioctl(fd_iav, IAV_IOC_MAP_BSB2, &info) < 0) {
		perror("IAV_IOC_MAP_BSB");
		return -1;
	}

	if (ioctl(fd_iav, IAV_IOC_MAP_DSP, &info) < 0) {
		perror("IAV_IOC_MAP_DSP");
		return -1;
	}

	mem_mapped = 1;
	return 0;
}

int bsreader()
{
	int fd_iav;
	bsreader_init_data_t  init_data;

	if ((fd_iav = open("/dev/iav", O_RDWR, 0)) < 0) {
		perror("/dev/iav");
		return -1;
	}
	if (map_bsb(fd_iav) < 0) {
		printf("map bsb failed\n");
		return -1;
	}

	memset(&init_data, 0, sizeof(init_data));
	init_data.fd_iav = fd_iav;
	init_data.max_stream_num = 4;
	init_data.ring_buf_size[0] = 1024*1024*4;  // 4MB
	init_data.ring_buf_size[1] = 1024*1024*2;  // 2MB
	init_data.ring_buf_size[2] = 1024*1024*1;  // 1MB
	init_data.ring_buf_size[3] = 1024*1024*1;  // 1MB

	/* Enable cavlc encoding when configured.
	 * This option will use more memory in bsreader on A5s arch.
	 */
	init_data.cavlc_possible = 1;

	if (bsreader_init(&init_data) < 0) {
		printf("bsreader init failed \n");
		return -1;
	}

	if (bsreader_open() < 0) {
		printf("bsreader open failed \n");
		return -1;
	}
	return 0;
}


static void sighandler(int sig_no)
{
	if (bsreader_close() < 0) {
		printf("bsreader_close() failed!\n");
	}
	exit(0);
}
int reset()
{
    bsreader_reset(streamID);
    return 0;
}
int main(int argc, char** argv) 
{
    FILE *fp;
    int ret =0;
    int i =1000;
    bsreader_frame_info_t frame_info;

    fp_test = fopen("file_test.h264", "a");
    
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	signal(SIGTERM, sighandler);

	if (0!=bsreader())
    {
		exit(-2);
    }
    reset();
    do{
        if (bsreader_get_one_frame(1, &frame_info) < 0) {
            printf("bs reader gets frame error\n");
            return -1;
        }
        if ((ret = fwrite(frame_info.frame_addr, frame_info.frame_size, 1, fp)) != frame_info.frame_size)
        {
            printf("write errorframe_info.frame_size[%d]size[%d]\n", frame_info.frame_size, ret);
        }
        printf("get a frame write to file\n");
    }while(i--);

	return 0;
}


