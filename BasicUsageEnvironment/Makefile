default: all

MODULE_NAME		:= BasicUsageEnvironment

MODULE_LIBS		 =	lib$(MODULE_NAME).a

INCLUDES = -Iinclude -I../UsageEnvironment/include -I../groupsock/include

include ../lib.rules

LIB_OBJS = BasicUsageEnvironment0.o BasicUsageEnvironment.o \
	BasicTaskScheduler0.o BasicTaskScheduler.o \
	DelayQueue.o BasicHashTable.o

MODULE_TARGETS = $(MODULE_LIBS)

.PHONY:clean

all:$(MODULE_TARGETS)

$(MODULE_LIBS): $(LIB_OBJS)
	@$(AR) rucs  $@ $^

clean:
	@echo '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o $(MODULE_TARGETS) $(LIB_OBJS)
