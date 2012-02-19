#
# Makefile
#

## Directories
PWD   = $(CURDIR)
I_DIR = ${PWD}/include
S_DIR = ${PWD}/src
L_DIR = ${PWD}/lib
O_DIR = ${PWD}/obj
B_DIR = ${PWD}/bin


## Compiler & linker opts.
CC      = gcc
CCFLAGS = --pedantic -Wall -Werror -I ${I_DIR}
LDFLAGS = -s -lm -L ${L_DIR}


## Makefile opts.
SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .h .c .o


## Files options
TARGET = ${B_DIR}/main
OBJS = $(patsubst ${S_DIR}/%.c, ${O_DIR}/%.o, $(wildcard ${S_DIR}/*.c))


## Linkage
${TARGET}: ${OBJS}
	${CC} ${LDFLAGS} -o $@ $^


## Compilation
${O_DIR}/%.o: ${S_DIR}/%.c
	${CC} ${CCFLAGS} -c -o $@ $<


## Make options
.PHONY: clean

all:
	make ${TARGET}

clean:
	rm --force ${OBJS} ${TARGET}

clean-obj:
	rm --force ${OBJS}

clean-all:
	make clean

help:
	@echo "Type:"
	@echo "  'make all':      Build"
	@echo "  'make clean':    Cleans bianry and object files"
	@echo "  'make clean-obj: Cleans only object files"
	@echo ""
	@echo " Binary will be placed in '${TARGET}'"

