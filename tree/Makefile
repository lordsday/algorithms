CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =

TREE_SRCS = tree.c
TREE_OBJS = $(TREE_SRCS:.c=.o)
TREE = tree

TRAVERSE_SRCS = traverse.c
TRAVERSE_OBJS = $(TRAVERSE_SRCS:.c=.o)
TRAVERSE = traverse

all: $(TREE) $(TRAVERSE)

$(TREE): $(TREE_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TRAVERSE): $(TRAVERSE_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TREE) $(TRAVERSE)
