FLOYD = floyd
FLOYD_OBJS = floyd.o

DIJKSTRA = dijkstra
DIJKSTRA_OBJ = dijkstra.o

CFLAGS = -c -std=c99

all: $(FLOYD) $(DIJKSTRA)

$(FLOYD): $(FLOYD_OBJS)
	$(CC) $^ -o $@

$(DIJKSTRA): $(DIJKSTRA_OBJ)
	$(CC) $^ -o $@

clean:
	rm -f *.o $(FLOYD) $(DIJKSTRA)
