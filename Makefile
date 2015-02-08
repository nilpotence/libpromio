INCLUDES=

CFLAGS=
LDFLAGS=-fPIC
CXXFLAGS=${INCLUDES} ${CFLAGS} -MMD -MP

DEBUG=-g

SRC=$(shell cd src; find . -name "*.c")
OBJ=$(addprefix build/obj/, $(SRC:.c=.o))


.PHONY: all clean


test: lib tests/peerA.c tests/peerB.c
	gcc -Idist/includes -Ldist tests/peerA.c -o tests/peerA -lpromio
	gcc -Idist/includes -Ldist tests/peerB.c -o tests/peerB -lpromio

lib: copyDir copyHeaders dist/libpromio.so

dist/libpromio.so: $(OBJ)
	gcc ${DEBUG} ${LDFLAGS} $^ -shared -o $@

build/obj/%.o: src/%.c
	gcc ${DEBUG} ${LDFLAGS} ${CXXFLAGS} $< -c -o $@
        
-include $(shell find ./build/ -name "*.d")

copyDir:
	@cd src; find ./ -type d -not -name ".*" -exec mkdir -p ../build/obj/{} \;

copyHeaders:
	@cd src; find ./ -type d -not -name ".*" -exec mkdir -p ../dist/includes/promio/{} \;
	@cd src; find ./ -not -type d -name "*.h" -exec cp {} ../dist/includes/promio/{} \;

clean:
	rm -Rf build/*
	rm -Rf dist/*
	mkdir -p build
	mkdir -p dist
	mkdir build/obj
	mkdir dist/includes
	mkdir dist/includes/promio
