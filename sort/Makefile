CC = gcc
CFLAGS = -c -std=c99
LDFLAGS =

QUICK_SORT_SRCS = quick_sort.c
QUICK_SORT_OBJS = $(QUICK_SORT_SRCS:.c=.o)
QUICK_SORT = quick_sort

MERGE_SORT_SRCS = merge_sort.c
MERGE_SORT_OBJS = $(MERGE_SORT_SRCS:.c=.o)
MERGE_SORT = merge_sort

all: $(QUICK_SORT) $(MERGE_SORT)

$(QUICK_SORT): $(QUICK_SORT_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(MERGE_SORT): $(MERGE_SORT_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(QUICK_SORT) $(MERGE_SORT)
