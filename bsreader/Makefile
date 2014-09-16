#/*
#****************************************************************************
#*
#** \file      Makefile
#**
#** \version   
#**
#** \brief     
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

PWD			:= $(shell pwd)
AMBABUILD_TOPDIR		?= $(AMBA_SDK_TOP)/ambarella
LIB_NAME	:= bsreader
LIB_FILE	:= lib$(LIB_NAME).a
LIB_PATH	:= $(AMBABUILD_TOPDIR)/prebuild/bsreader

include common.mk
export AMBABUILD_TOPDIR
LIVE555_DEBUG       := $(PWD)/../debug

INCLUDES = -I$(AMBABUILD_TOPDIR)/build/include -I$(AMBABUILD_TOPDIR)/build/include/arch -I$(AMBABUILD_TOPDIR) -I$(LIVE555_DEBUG)
COMPILE_CFLAG = -Wall
DEBUG_FLAG = -O3
CFLAGS = $(INCLUDES) $(DEBUG_FLAG) $(COMPILE_CFLAG) $(PACKAGES_CFLAG)
export PATH:=$(PATH):$(TOOLCHAIN_PATH)

UNIT_TEST_LDFLAG	?= $(AMBARELLA_LDFLAGS)

.PHONY: all clean

all:
	$(AMBA_MAKEFILE_V)echo "  [Build $(LIB_NAME)]:"
	@echo "    compile bsreader..."
	$(AMBA_MAKEFILE_V)$(CROSS_COMPILE)gcc $(CFLAGS) -c bsreader.c  -o bsreader.o
	$(AMBA_MAKEFILE_V)$(CROSS_COMPILE)gcc $(CFLAGS) -c fifo.c -o fifo.o
	$(AMBA_MAKEFILE_V)$(CROSS_COMPILE)ar rucs $(LIB_FILE) bsreader.o fifo.o
	$(AMBA_MAKEFILE_V)mkdir -p $(LIB_PATH)/
	$(AMBA_MAKEFILE_V)cp $(LIB_FILE) $(LIB_PATH)/

clean:
	$(AMBA_MAKEFILE_V)echo "  [Clean $(LIB_NAME)]:"
	$(AMBA_MAKEFILE_V)rm -f *.a *.o
	$(AMBA_MAKEFILE_V)rm -fr $(LIB_PATH)

