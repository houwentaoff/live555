###############################################
#
# app/ipcam/rtsp/rules.mk
#
# 2010/02/03 - [Jian Tang] created file
#
# Copyright (C) 2010, Ambarella, Inc.
#
# All rights reserved. No Part of this file may be reproduced, stored
# in a retrieval system, or transmitted, in any form, or by any means,
# electronic, mechanical, photocopying, recording, or otherwise,
# without the prior consent of Ambarella, Inc.
#
###############################################

COMPILER := gcc
ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE   := arm-linux-
endif
ifeq ($(TOOLCHAIN_PATH),)
TOOLCHAIN_PATH  := $(ARM_LINUX_TOOLCHAIN_DIR)/staging_dir/usr/bin
endif
ifeq ($(SYS_LIB_DIR),)
SYS_LIB_DIR     := $(ARM_LINUX_TOOLCHAIN_DIR)/staging_dir/lib
endif
ifeq ($(PREBUILD_DIR),)
PREBUILD_DIR	:= arm_926t_oabi
export PREBUILD_DIR
endif

CC = $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)$(COMPILER)
CXX = $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)g++
LD = $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)$(COMPILER)
MKDIR = mkdir -p
RM = rm -rf
AR = $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)ar
RANLIB= $(TOOLCHAIN_PATH)/$(CROSS_COMPILE)ranlib

debug = 

##### Change the following for your environment: 
COMPILE_OPTS			=	$(INCLUDES) -I. -DSOCKLEN_T=socklen_t -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64
C						=	c
C_COMPILER				=	$(CC)
C_FLAGS				=	$(COMPILE_OPTS)
CPP						=	cpp
CPLUSPLUS_COMPILER	=	$(CXX)
CPLUSPLUS_FLAGS		=	$(COMPILE_OPTS) $(APP_CFLAG) -DBSD=1 -g -O2 -fpermissive
OBJ						=	o
LINK					=	$(CXX) -o 
LINK_OPTS				=	-L. -g -O2
CONSOLE_LINK_OPTS		=	$(LINK_OPTS)
LIBRARY_LINK			=	$(AR) rucs 
LIBRARY_LINK_OPTS		=
LIB_SUFFIX				=	a
MODULE_LIBS			=	lib$(MODULE_NAME).$(LIB_SUFFIX)
##pthread ?
LIBS_FOR_CONSOLE_APPLICATION = -pthread
LIBS_FOR_GUI_APPLICATION =
EXE						=
EXE_DIR					=
##### End of variables to change



