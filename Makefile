#/*
#****************************************************************************
#*
#** \file      Makefile
#**
#** \version   
#**
#** \brief     live555 14.05
#**
#** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOFORTUNE SEMICONDUCTOR
#**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR 
#**            OMMISSIONS.
#**
#** (C) Copyright 2012-2013 by GOKE MICROELECTRONICS CO.,LTD
#**
#****************************************************************************
#*/

default: all
SUBDIRS=liveMedia groupsock UsageEnvironment BasicUsageEnvironment testProgs mediaServer server

PWD			:= $(shell pwd)
AMBABUILD_TOPDIR	?= $(word 1, $(subst /app/ipcam, ,$(PWD)))

export AMBABUILD_TOPDIR

include lib.rules

#include $(AMBABUILD_TOPDIR)/build/core/common.mk

.PHONY: all clean

all:
	-@$(ECHO) -e "\033[5;41;32m  Building rtsp ...   \033[0m"
	for d in $(SUBDIRS); do [ -d $$d ] && $(MAKE) -C $$d; done

clean:
	-@$(ECHO) -e "\033[5;41;32m  Cleaning rtsp ...   \033[0m"
	for d in $(SUBDIRS); do [ -d $$d ] && $(MAKE) -C $$d clean; done
	rm -rf *.o *.a
