# Makefile for building demo applications.


# Edit this file to compile extra C files into their own programs.

TARGETS= sum_on_many_threads

CROSS_TOOL = 
CC_CPP = $(CROSS_TOOL)g++
CC_C = $(CROSS_TOOL)gcc

CFLAGS = -Wall -g -std=c99 -Werror -pthread

all: clean $(TARGETS)

$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@ 

clean:
	rm -f $(TARGETS)