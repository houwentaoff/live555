/*
****************************************************************************
*
** \file      debug.h
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
#ifndef __DEBUG_H__
#define __DEBUG_H__

/* #####   DEBUG MACROS   ########################################################### */
#define     INOUT_DEBUG                          1  /*1 is open , o is close */
#define     LIVE555_DEBUG                          1  /*1 is open , 0 is close */
#define     LIVE555_ERROR                          1  /*1 is open , 0 is close */







#if INOUT_DEBUG
#define FUN_IN(fmt, args...)              printf("==> %s %s():"fmt"\n", __FILE__, __func__, ##args)/*  */
#define FUN_OUT(fmt, args...)             printf("<== %s %s():"fmt"\n", __FILE__, __func__, ##args) /*  */
#else
#define FUN_IN(fmt, args...)
#define FUN_OUT(fmt, args...)
#endif

#if LIVE555_DEBUG
#define PRT_DBG(fmt, args...)             printf("%s():"fmt"\n", __func__, ##args)/*  */
#else
#define PRT_DBG(fmt, args...)
#endif

#if LIVE555_ERROR
#define PRT_ERR(fmt, args...)                                                               \
do                                                                                          \
{                                                                                           \
    printf("\033[5;41;32m [ERROR] %s ---> %s ():line[%d]:\033[0m\n", __FILE__, __func__, __LINE__);      \
    printf(" "fmt, ##args);                                                                 \
}while(0)    /* */
#else
#define PRT_ERR(fmt, args...)
#endif

#endif //__DEBUG_H__
