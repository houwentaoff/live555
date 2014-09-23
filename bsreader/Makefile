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

MODULE_NAME	   := bsreader
MODULE_LIBS		= lib$(MODULE_NAME).a
MODULE_TARGETS  = $(MODULE_LIBS)

INCLUDES 		= -I../debug

C_FLAGS  		= $(INCLUDES)

include ../lib.rules


LIB_OBJS  		= bsreader.o fifo.o

.PHONY:clean

all:$(MODULE_TARGETS)

$(MODULE_LIBS): $(LIB_OBJS)
	@$(AR) rucs $@  $^

clean:
	@$(ECHO) '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o $(MODULE_TARGETS) $(LIB_OBJS)
