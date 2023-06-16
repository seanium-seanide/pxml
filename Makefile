SRCDIR=src
OBJDIR=obj
BINDIR=bin
INCLUDEDIR=include

CC=clang++
CFLAGS=-W -Wall -std=c++14 -g -I $(INCLUDEDIR)
LDFLAGS=

BIN=$(BINDIR)/pxml_test
OBJ=$(OBJDIR)/main.o $(OBJDIR)/Document.o $(OBJDIR)/Node.o

all: directories $(BIN)

directories:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCLUDEDIR)/main.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/Document.o: $(SRCDIR)/Document.cpp $(INCLUDEDIR)/Document.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/Node.o: $(SRCDIR)/Node.cpp $(INCLUDEDIR)/Node.h
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
	rmdir $(BINDIR)
	rmdir $(OBJDIR)

.PHONY: run
run:
	./$(BIN)
