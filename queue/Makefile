CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =
SRCS = queue.c
OBJS = $(SRCS:.c=.o)
TARGET = queue

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
