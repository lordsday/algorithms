CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =

FLOYD_SRCS = floyd.c
FLOYD_OBJS = $(FLOYD_SRCS:.c=.o)
FLOYD = floyd

DIJKSTRA_SRCS = dijkstra.c
DIJKSTRA_OBJS = $(DIJKSTRA_SRCS:.c=.o)
DIJKSTRA = dijkstra

# BF_SRCS = bellman-ford.c
# BF_OBJS = $(BF_SRCS:.c=.o)
# BF = bellman-ford

all: $(FLOYD) $(BF) $(DIJKSTRA)

$(FLOYD): $(FLOYD_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(DIJKSTRA): $(DIJKSTRA_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# $(BF): $(BF_OBJS)
# 	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(FLOYD) $(BF) $(DIJKSTRA)
