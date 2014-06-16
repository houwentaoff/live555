##### Change the following for your environment:
##### End of variables to change

default: all

AMBABUILD_TOPDIR	= $(word 1, $(subst /app/ipcam, ,$(shell pwd)))
MODULE_NAME		= BasicUsageEnvironment

export AMBABUILD_TOPDIR

INCLUDES = -Iinclude -I../UsageEnvironment/include -I../groupsock/include

-include $(AMBABUILD_TOPDIR)/build/app/common.mk
-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/config.mk

LIB_OBJS = BasicUsageEnvironment0.$(OBJ) BasicUsageEnvironment.$(OBJ) \
	BasicTaskScheduler0.$(OBJ) BasicTaskScheduler.$(OBJ) \
	DelayQueue.$(OBJ) BasicHashTable.$(OBJ)

MODULE_TARGETS = $(MODULE_LIBS)

-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/rules.mk

##### Any additional, platform-specific rules come here:
