CC = gcc
CFLAGS = -c -std=c99

TARGET = array
OBJS = array.o

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -f *.o $(TARGET)
