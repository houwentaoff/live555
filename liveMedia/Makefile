default: all

MODULE_NAME		:= liveMedia

MODULE_LIBS		 =	lib$(MODULE_NAME).a

INCLUDES = -Iinclude -I../UsageEnvironment/include -I../groupsock/include

include depend.mk 
include ../lib.rules

MODULE_TARGETS   = $(MODULE_LIBS) 

.PHONY:clean

all:$(MODULE_TARGETS)

$(MODULE_LIBS): $(LIB_OBJS)
	@$(AR) rucs  $@ $^

clean:
	@echo '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o $(MODULE_TARGETS) $(LIB_OBJS)
