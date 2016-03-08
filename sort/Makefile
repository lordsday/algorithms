CC = gcc
CFLAGS = -c -std=c99

QUICK_SORT = quicksort
QUICK_SORT_OBJS = quicksort.o

MERGE_SORT = merge_sort
MERGE_SORT_OBJS = merge_sort.o

all: $(QUICK_SORT) $(MERGE_SORT)

$(QUICK_SORT): $(QUICK_SORT_OBJS)
	$(CC) $^ -o $@

$(MERGE_SORT): $(MERGE_SORT_OBJS)
	$(CC) $^ -o $@

clean:
	rm -f *.o $(QUICK_SORT) $(MERGE_SORT) $(QUICK_SORT_OBJS) $(MERGE_SORT_OBJS)
