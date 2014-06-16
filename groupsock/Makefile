default: all

AMBABUILD_TOPDIR	= $(word 1, $(subst /app/ipcam, ,$(shell pwd)))
MODULE_NAME		= groupsock

export AMBABUILD_TOPDIR

INCLUDES = -Iinclude -I../UsageEnvironment/include

-include $(AMBABUILD_TOPDIR)/build/app/common.mk
-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/config.mk

LIB_OBJS = GroupsockHelper.$(OBJ) GroupEId.$(OBJ) inet.$(OBJ) \
		Groupsock.$(OBJ) NetInterface.$(OBJ) NetAddress.$(OBJ) \
		IOHandlers.$(OBJ)

MODULE_TARGETS = $(MODULE_LIBS)

-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/rules.mk

