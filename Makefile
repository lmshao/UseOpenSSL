CC = g++
LD = g++
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

CPPFLAGS = -Wall -O2 -std=c++11 -Wno-c++11-extensions -Wno-c++11-long-long
INCLUDE = -I./include

OS = $(shell uname -s | tr [A-Z] [a-z])
#$(info OS=$(OS))

ifeq ($(OS), darwin)
LIB = -L./libs/mac -lcrypto -lssl
endif

ifeq ($(OS), linux)
LIB = -L./libs/linux -lcrypto -lssl
endif

TARGET = UseOpenSSL

.PHONY:all clean

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LIB)
	@echo "\033[0m\033[1A"

%.o:%.cpp
	@echo "\033[32m\033[1A"
	$(CC) -c $^ $(INCLUDE) $(CPPFLAGS)

clean:
	@echo "\033[32m\033[1A"
	rm -f $(OBJS) $(TARGET)
	@echo "\033[0m\033[1A"
