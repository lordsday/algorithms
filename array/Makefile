CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =
SRCS = array.c
OBJS = $(SRCS:.c=.o)
TARGET = array

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
