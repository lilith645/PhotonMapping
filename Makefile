OBJS = main.cpp

OS := $(shell uname)
CC = clang++

COMPILER_FLAGS = -I./staticlibs/ -std=c++14

ifeq ($(OS), Linux)
INCLUDE_PATHS =  -I/usr/include -I/usr/include/freetype2
LIBRARY_PATHS =  -L/usr/lib

LINKER_FLAGS = -g -lGL -lglfw -lGLEW

endif

$(info OS is $(OS))

OBJ_NAME = ./PhotonMapping

all: $(OBJS)
				$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

ifeq ($(OS), Linux)
run:
				./PhotonMapping
endif

