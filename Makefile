
###############################################
#
# app/ipcam/live_555/livemedia
#
# 2014/06/14 - [Sean HOu] created file
#
# 
#
# All rights reserved. No Part of this file may be reproduced, stored
# in a retrieval system, or transmitted, in any form, or by any means,
# electronic, mechanical, photocopying, recording, or otherwise,
# without the prior consent of Ambarella, Inc.
#
###############################################

default: all

PWD			:= $(shell pwd)
AMBABUILD_TOPDIR	?= $(word 1, $(subst /app/ipcam, ,$(PWD)))

export AMBABUILD_TOPDIR

include $(AMBABUILD_TOPDIR)/build/core/common.mk

.PHONY: all depend clean

all:
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/liveMedia $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/groupsock $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/UsageEnvironment $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/BasicUsageEnvironment $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/testProgs $@
#	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/testH264 $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/mediaServer $@

clean:
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/liveMedia $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/groupsock $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/UsageEnvironment $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/BasicUsageEnvironment $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/testProgs $@
#	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/testH264 $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/mediaServer $@
	rm -rf obj/
	
depend:
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/liveMedia $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/groupsock $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/UsageEnvironment $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/BasicUsageEnvironment $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/testProgs $@
#	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/testH264 $@
	$(AMBA_MAKEFILE_V)$(MAKE) -C $(AMBABUILD_TOPDIR)/app/ipcam/live_555/mediaServer $@

