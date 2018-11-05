# Makefile to compile programs
# src/ - source files *.cpp, *.hpp
# obj/ - object file  *.o
# bin/ - exec files   *
# Author: Aldo Nunez

CC := clang++
FLAGS := -Wall
LIBS := -lwiringPi

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=obj/%.o)
BIN := $(OBJ:obj/%.o=bin/%)	

all: $(BIN) $(OBJ)

bin/%: obj/%.o
	$(CC) -o $@ $< $(LIBS) $(FLAGS)

obj/%.o: src/%.cpp src/%.hpp
	$(CC) -o $@ -c $<

obj/%.o: src/%.cpp
	@echo "Compiling:"  $<
	$(CC) -o $@ -c $<

.PHONY: clean

clean:
	@echo "Cleaning"
	rm -f $(OBJ) $(BIN) 
