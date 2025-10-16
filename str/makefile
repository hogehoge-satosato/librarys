CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = strlibs.c main.c ../sort/sortlibs.c
OBJ = $(patsubst %.c, build/%.o, $(notdir $(SRC)))

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

build/%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


build/%.o: ../sort/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr build $(TARGET)

.PHONY: all clean