/*
 * =====================================================================================
 *       Copyright (c), 2013-2020, Goke C&S.
 *       Filename:  rtsp_test1.cpp
 *
 *    Description:  测试live555 接口
 *         Others:
 *   
 *        Version:  1.0
 *        Date:  Sunday, May 18, 2014 02:17:36 HKT
 *       Revision:  none
 *       Compiler:  arm-gcc
 *
 *         Author:  Sean , houwentaoff@gmail.com
 *   Organization:  Goke
 *        History:   Created by housir
 *
 * =====================================================================================
 */

#include <BasicUsageEnvironment.hh>
#include "liveMedia.hh"

#include "DynamicRTSPServer.hh"
#include "version.hh"
#include <stdlib.h>

//#define    H264_FILE  "slamtv60.264"        /*  */
#define    H264_FILE_1  "tc10.264"        /*  */
#define    H264_FILE_2  "slamtv60.264"        /*  */
#define    LIVE555_STREAM "SeanHou"            /*  */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * ===================================================================================
 */
int main ( int argc, char *argv[] )
{
    ServerMediaSession* sms;
    /*Sean Hou: 1.创建调度器 */
    TaskScheduler* schedule = BasicTaskScheduler::createNew();
    /*Sean Hou: 2.创建交互环境 */
    UsageEnvironment* env = BasicUsageEnvironment::createNew(*schedule);
    /*Sean Hou: 3.创建RSTP服务器 */
    RTSPServer *rtsp_server = RTSPServer::createNew(*env, 554);

    if(NULL == rtsp_server)
    {
        rtsp_server = RTSPServer::createNew(*env, 8554);
    }
    if(NULL == rtsp_server)
    {
        *env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
        exit(1);
    }
/*Sean Hou: 打印出提示方便访问 */
    *env << "Sean Hou play h264!\n"
         << rtsp_server->rtspURLPrefix()<<"\n";

//    sms = rtsp_server->lookupServerMediaSession("./slamtv60.264");
    /*Sean Hou:  4.创建会话*/
    sms = ServerMediaSession::createNew(*env, LIVE555_STREAM);
//    sms->addSubsession(PassiveServerMediaSubsession::createNew(*videoSink, rtcp));
    /*Sean Hou: 5.添加视频子会话,可以继续添加其他子会话 如:音频*/
    sms->addSubsession(H264VideoFileServerMediaSubsession::createNew(*env, H264_FILE_2, True));
//    sms->addSubsession(H264VideoFileServerMediaSubsession::createNew(*env, H264_FILE_1, False));
    /*Sean Hou: 6.为RTSPserver添加会话*/
    rtsp_server->addServerMediaSession(sms);

    env->taskScheduler().doEventLoop();

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
