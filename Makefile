CC=g++
CFLAGS=-c -g -Wall `root-config --cflags`
LDFLAGS=`root-config --glibs`
GFORT=
SOURCES=read.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=read
 all: $(SOURCES) $(EXECUTABLE)
 $(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(GFORT)
 .cc.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGS)
 clean:
	rm ./*.o ./read


