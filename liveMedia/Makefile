default: all

MODULE_NAME		:= liveMedia

MODULE_LIBS		 =	lib$(MODULE_NAME).a

INCLUDES = -Iinclude -I../UsageEnvironment/include -I../groupsock/include

include ../config.mk
-include ./depend.mk #依赖关系
include ../lib.rules
LIBRARY_LINK	 =	$(AR) rucs 

MODULE_TARGETS = $(MODULE_LIBS) 

all:$(MODULE_TARGETS)

$(MODULE_LIBS): $(LIB_OBJS)
	@$(LIBRARY_LINK) $@ $(LIB_OBJS)

clean:
	@echo '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.$(OBJ) $(MODULE_TARGETS) core *.core *~ include/*~ .depend
	@$(RM) $(LIB_OBJS)
