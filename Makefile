INCLUDES=

CFLAGS=
LDFLAGS=-fPIC
CXXFLAGS=${INCLUDES} ${CFLAGS} -MMD -MP

DEBUG=-g

SRC=$(shell cd src; find . -name "*.c")
OBJ=$(addprefix build/obj/, $(SRC:.c=.o))


.PHONY: all clean

all: copyDir dist/libpromio.so

dist/libpromio.so: $(OBJ)
	gcc ${DEBUG} ${LDFLAGS} $^ -shared -o $@

build/obj/%.o: src/%.c
	gcc ${DEBUG} ${LDFLAGS} ${CXXFLAGS} $< -c -o $@
        
-include $(shell find ./build/ -name "*.d")

copyDir:
	@cd src; find ./ -type d -not -name ".*" -exec mkdir -p ../build/obj/{} \;

clean:
	rm -Rf build/*
	rm -Rf dist/*
	mkdir build/obj
