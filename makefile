# Root Makefile-lsfml-network
.SUFFIXES:

# Var
CC = g++
CFLAGS = -Wall

LIB = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

BUILDDIR = build
SRCDIR = source/src

SRCEXT = cpp
TARGET = bin/ctd

SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))


OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

INC = -Isource/include


$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB) "; $(CC) $^ -o $(TARGET) $(LIB)


$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

run:
	./bin/ctd

.PHONY: clean
