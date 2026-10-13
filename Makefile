CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=l5interface.c l5vectors.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=vectors
all: $(EXECUTABLE)
# Pull in dependency info for existing .o files
-include $(OBJECTS:.o=.d)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) *.d
.PHONY: all clean