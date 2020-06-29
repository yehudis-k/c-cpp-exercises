TARGET=main
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)
INC_FLAGS=-I../include
CC=g++
CFLAGS= -c -pedantic -Wall -Werror -Wconversion -ansi -g $(INC_FLAGS)
CXXFLAGS=$(CFLAGS)
LDFLAGS=-g
.PHONY: clean run gdb val
$(TARGET): $(OBJS)
include .depends
.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val:
	valgrind --leak-check=full ./$(TARGET)













