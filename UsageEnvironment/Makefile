default: all

MODULE_NAME		:= UsageEnvironment

MODULE_TARGETS   = $(MODULE_LIBS)

MODULE_LIBS		 =	lib$(MODULE_NAME).a

INCLUDES  		 = -Iinclude -I../groupsock/include

include ../lib.rules

LIB_OBJS         = UsageEnvironment.o HashTable.o strDup.o



.PHONY:clean

all:$(MODULE_TARGETS)

$(MODULE_LIBS): $(LIB_OBJS)
	@$(AR) rucs  $@ $^

clean:
	@echo '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o $(MODULE_TARGETS) $(LIB_OBJS)
