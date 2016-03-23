CC = gcc
CFLAGS = -c -std=c99

TARGET = hash
OBJS = hash.o

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -f *.o $(TARGET)
