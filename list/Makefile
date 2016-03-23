CC = gcc
CFLAGS = -c -std=c99

TARGET = list
OBJS = list.o

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -f *.o $(TARGET)
