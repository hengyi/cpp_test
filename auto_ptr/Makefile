.PHONY: clean
AOBJS	:= $(patsubst %.s, %.o, $(wildcard *.s))
COBJS	:= $(patsubst %.c, %.o, $(wildcard *.c))
CPPOBJS	:= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJS	:= $(AOBJS) $(COBJS) $(CPPOBJS)

APP := app
LDFLAGS :=
#CC := /complie/android/hehaiyi/firefly_git/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-gcc
#CC=arm-linux-gnueabihf-gcc
CC=g++
all: $(OBJS)
	$(CC) -o $(APP) $^ $(LDFLAGS)
clean:
	rm -f $(OBJS) $(APP)



