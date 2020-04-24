TARGET = shiftgear
OBJS = main.o game.o

CFLAGS = -Wall -Wextra -g
CC = gcc

INCLUDES=
LIBS=-lSDL2

all: $(TARGET)
	echo Created $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(INCLUDES) $(LIBS)

%.o: %c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDES) $(LIBS)

clean:
	rm $(OBJS) $(TARGET)