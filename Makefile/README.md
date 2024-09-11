# Makefile

CC = gcc
CFLAGS = -Iinclude
OBJ = src/rapid_xor_hash.o src/main.o
TARGET = rapid_xor_hash

all: $(TARGET)

$(TARGET): $(OBJ)
$(CC) -o $@ $(OBJ)

src/rapid_xor_hash.o: src/rapid_xor_hash.c
$(CC) $(CFLAGS) -c src/rapid_xor_hash.c -o src/rapid_xor_hash.o

src/main.o: src/main.c
$(CC) $(CFLAGS) -c src/main.c -o src/main.o

clean:
rm -f $(TARGET) $(OBJ)
