
default: all

AMBABUILD_TOPDIR  = $(word 1, $(subst /app/ipcam, ,$(shell pwd)))
MODULE_NAME		:= liveMedia

export AMBABUILD_TOPDIR

INCLUDES = -Iinclude -I../UsageEnvironment/include -I../groupsock/include

-include $(AMBABUILD_TOPDIR)/build/app/common.mk
-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/config.mk #编译环境

-include ./depend.mk #依赖关系

MODULE_TARGETS = $(MODULE_LIBS) #MODULE_LIBS定义在config.mk

-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/rules.mk #编译命令


#.$(CPP).$(OBJ):
#	$(CPLUSPLUS_COMPILER) -c $(CPLUSPLUS_FLAGS) $<


#clean:
#	-rm -rf *.$(OBJ) $(ALL) core *.core *~ include/*~

#install: install1 $(INSTALL2)
#install1: $(LIVEMEDIA_LIB)
#	 install -d $(DESTDIR)$(PREFIX)/include/liveMedia $(DESTDIR)$(LIBDIR)
#	 install -m 644 include/*.hh $(DESTDIR)$(PREFIX)/include/liveMedia
#	 install -m 644 $(LIVEMEDIA_LIB) $(DESTDIR)$(LIBDIR)
#install_shared_libraries: $(LIVEMEDIA_LIB)
#	 ln -s $(NAME).$(LIB_SUFFIX) $(DESTDIR)$(LIBDIR)/$(NAME).$(SHORT_LIB_SUFFIX)
#	 ln -s $(NAME).$(LIB_SUFFIX) $(DESTDIR)$(LIBDIR)/$(NAME).so

##### Any additional, platform-specific rules come here:
