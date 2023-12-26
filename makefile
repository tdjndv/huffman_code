CC=g++

OBJECTS = main.cpp huffman.cpp

all:prog

prog:$(OBJECTS)
	$(CC) $(OBJECTS)

clean:
	rm -rf *.out
