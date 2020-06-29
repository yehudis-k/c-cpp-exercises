TARGET=main

SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

INC_FLAGS=-I../include
CC=g++
CFLAGS=-pedantic -c -Wall -Werror -Wconversion -ansi -g -D _DEBUG=m $(INC_FLAGS)
CXXFLAGS= $(CFLAGS)
LDFLAGS=-g
#LDLIBS = -lgtest -lgtest_main -pthread


.PHONY: clean run gdb valgrind

$(TARGET): $(OBJS)

include .depends

.depends:
    $(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
    rm -f $(OBJS) $(TARGET)

run: $(TARGET)
    ./$(TARGET)

gdb: $(TARGET)
    gdb -q ./$(TARGET)

valgrind: 
    valgrind --leak-check=full ./$(TARGET)



