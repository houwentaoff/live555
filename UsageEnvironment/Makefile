default: all

AMBABUILD_TOPDIR	= $(word 1, $(subst /app/ipcam, ,$(shell pwd)))
MODULE_NAME		= UsageEnvironment

export AMBABUILD_TOPDIR

INCLUDES = -Iinclude -I../groupsock/include
##### Change the following for your environment:
-include $(AMBABUILD_TOPDIR)/build/app/common.mk
-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/config.mk
##### End of variables to change




LIB_OBJS = UsageEnvironment.$(OBJ) HashTable.$(OBJ) strDup.$(OBJ)

#$(USAGE_ENVIRONMENT_LIB): $(OBJS)
#	$(LIBRARY_LINK)$@ $(LIBRARY_LINK_OPTS) $(OBJS)

#.$(C).$(OBJ):
#	$(C_COMPILER) -c $(C_FLAGS) $<       

#.$(CPP).$(OBJ):
#	$(CPLUSPLUS_COMPILER) -c $(CPLUSPLUS_FLAGS) $<


MODULE_TARGETS = $(MODULE_LIBS)

-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/rules.mk
##### Any additional, platform-specific rules come here:
