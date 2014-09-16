##
## common.mk
##
## History:
##    2009/07/08 - [Anthony Ginger] Create
##
## Copyright (C) 2004-2009, Ambarella, Inc.
##
## All rights reserved. No Part of this file may be reproduced, stored
## in a retrieval system, or transmitted, in any form, or by any means,
## electronic, mechanical, photocopying, recording, or otherwise,
## without the prior consent of Ambarella, Inc.
##

include $(AMBABUILD_TOPDIR)/build/core/functions.mk
include $(AMBABUILD_TOPDIR)/build/core/common.mk

ifeq ($(BUILD_AMBARELLA_PACKAGES_OPT_ARMV6), y)
PACKAGES_CFLAG		+= -march=armv6k -mtune=arm1136j-s -msoft-float -mlittle-endian
else
ifeq ($(BUILD_AMBARELLA_PACKAGES_OPT_ARMV7), y)
PACKAGES_CFLAG		+= -march=armv7-a -mlittle-endian
ifeq ($(BUILD_AMBARELLA_PACKAGES_OPT_NEON), y)
PACKAGES_CFLAG    += -mfloat-abi=softfp -mfpu=neon
else
PACKAGES_CFLAG    += -msoft-float
endif
else
PACKAGES_CFLAG		+= -march=armv5te -mtune=arm9tdmi
endif
endif

PACKAGES_CFLAG    += $(call cc-option,-mno-unaligned-access,)

export PACKAGES_CFLAG
export PATH:=$(TOOLCHAIN_PATH):$(PATH)

