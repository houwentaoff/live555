default: all

MODULE_NAME	   := groupsock
MODULE_LIBS		= lib$(MODULE_NAME).a
MODULE_TARGETS  = $(MODULE_LIBS)

INCLUDES 		= -Iinclude -I../UsageEnvironment/include

C_FLAGS  		= $(INCLUDES)

include ../lib.rules

LIB_OBJS        = GroupsockHelper.o GroupEId.o inet.o \
		Groupsock.o NetInterface.o NetAddress.o \
		IOHandlers.o

.PHONY:clean

all:$(MODULE_TARGETS)

$(MODULE_LIBS): $(LIB_OBJS)
	@$(AR) cr  $@  $^ 

clean:
	@$(ECHO) '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o $(MODULE_TARGETS) $(LIB_OBJS)
