CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =
SRCS = tree.c
OBJS = $(SRCS:.c=.o)
TARGET = tree

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
