CC = gcc
CFLAGS = -c -std=c99

TARGET = tree
OBJS = tree.o

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -f *.o $(TARGET)
