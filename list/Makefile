CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =
SRCS = list.c
OBJS = $(SRCS:.c=.o)
TARGET = list

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
