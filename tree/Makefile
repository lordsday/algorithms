CC = gcc
CFLAGS = -c -std=c99

TARGET = binary_search
OBJS = binary_search.o

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -f *.o $(TARGET)
