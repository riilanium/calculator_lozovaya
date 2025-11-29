CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -g
TARGET = bin/cmdcalc.exe

SOURCES = src/main.c src/calculator.c src/decoder.c
OBJECTS = obj/main.o obj/calculator.o obj/decoder.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@if not exist bin mkdir bin
	$(CC) $(OBJECTS) -o $@

obj/main.o: src/main.c include/calculator.h
	@if not exist obj mkdir obj
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/calculator.o: src/calculator.c include/calculator.h
	@if not exist obj mkdir obj
	$(CC) $(CFLAGS) -c src/calculator.c -o obj/calculator.o

obj/decoder.o: src/decoder.c include/calculator.h
	@if not exist obj mkdir obj
	$(CC) $(CFLAGS) -c src/decoder.c -o obj/decoder.o

clean:
	@if exist obj rmdir /s /q obj
	@if exist bin rmdir /s /q bin

run: $(TARGET)
	$(TARGET) 41 + 33 111 - 8 22 * 5 221 % 111 100 + 13 -k 2

.PHONY: all clean run