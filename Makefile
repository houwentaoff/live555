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

MODULE_NAME  	:= rtsp

SUBDIRS=liveMedia groupsock UsageEnvironment BasicUsageEnvironment testProgs mediaServer bsreader server

include lib.rules

.PHONY: all clean

all:
	-@$(ECHO) -e "\033[5;41;32m  Building $(MODULE_NAME) ...   \033[0m"
	for d in $(SUBDIRS); do [ -d $$d ] && $(MAKE) -C $$d; done

clean:
	-@$(ECHO) -e "\033[5;41;32m  Cleanina $(MODULE_NAME) ...   \033[0m"
	for d in $(SUBDIRS); do [ -d $$d ] && $(MAKE) -C $$d clean; done
	@$(RM) -rf *.o *.a
