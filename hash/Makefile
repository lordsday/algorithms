CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =
SRCS = hash.c
OBJS = $(SRCS:.c=.o)
TARGET = hash

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
