CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =
SRCS = binary_search.c
OBJS = $(SRCS:.c=.o)
TARGET = binary_search

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
