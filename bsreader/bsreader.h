/*
****************************************************************************
*
** \file      ./bsreader/bsreader.h
**
** \version   $Id:
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

#ifndef __BSREADER_LIB_H__
#define __BSREADER_LIB_H__


#ifdef __cplusplus
extern "C" {
#endif

#define MAX_BS_READER_SOURCE_STREAM  4	
#define MAX_BS_READER_FRAMES_OF_BITS_INFO		16



/* current implementation use IAV's bits_info_ex_t to be frame info*/

#define BS_READER_FRAME_STATUS_INVALID	0	/* invalid frames, info is useless */
#define BS_READER_FRAME_STATUS_FRESH	1	/* fresh meat */
#define BS_READER_FRAME_STATUS_DIRTY	2	/* the one being used */

typedef struct {
	u32	stream_id;
	u32	session_id;	//use 32-bit session id
	u32	frame_num;
	u32	pic_type;
	u32	PTS;
	u32  stream_end;  // 0: normal stream frames,  1: stream end null frame
} bs_info_t;


/* any frame stored in bsreader must has continuous memory */
typedef struct bsreader_frame_info_s {
	bs_info_t bs_info;	/* orignal information got from dsp */
	u8	*frame_addr; /* the actual address in stream buffer */
	u32	frame_size;	 /* the actual output frame size , including CAVLC */
} bsreader_frame_info_t;	


typedef struct bsreader_init_data_s {
	u32 max_stream_num;								/* should be no more than 4*/
	u32 ring_buf_size[MAX_BS_READER_SOURCE_STREAM];
	u32 max_buffered_frame_num;
	u8	policy;				/* 0:default drop old when ring buffer full,  1: drop new when ring buffer full*/
	u8	dispatcher_thread_priority;	 /*the dispatcher thread RT priority */		
	u8	reader_threads_priority;	/* the four reader threads' thread RT priority */
	u8	cavlc_possible; /* if it is 1, then it's possible to use CAVLC encoding, set to 0 if don't need CAVLC */
	int fd_iav;
}bsreader_init_data_t;


/* set init parameters, do nothing real*/
int bsreader_init(bsreader_init_data_t * bsinit);

/* create mutex and cond, allocate memory and do data initialization, threads initialization, also call reset write/read pointers */
int bsreader_open(void);

/* free all resources, close all threads, destroy all mutex and cond */
int bsreader_close(void);

/* get one frame out of the stream
   after the frame is read out, the frame still stays in ring buffer, until next bsreader_get_one_frame will invalidate it.
*/
int bsreader_get_one_frame(int stream, bsreader_frame_info_t * info);

/* flush (discard) and reset all data in ring buf (can flush selected ringbuf), 
   do not allocate or free ring buffer memory.
  */
int bsreader_reset(int stream);
int bsreader_unblock_reader(int stream);



#ifdef __cplusplus
}
#endif


#endif // __BSREADER_LIB_H__


