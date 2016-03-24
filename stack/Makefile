CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =

STACK_SRCS = stack.c
STACK_OBJS = $(STACK_SRCS:.c=.o)
STACK = stack


all: $(STACK)

$(STACK): $(STACK_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(STACK)
