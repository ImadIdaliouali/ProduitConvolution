CC = gcc
SRC = main.c
TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $^ -o $@
	./$@

clean:
	rm -f $(TARGET)

re: clean all