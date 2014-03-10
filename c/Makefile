# Purpose: Demonstrate usage of pkg-config with MRPT libraries
# By: Jose Luis Blanco, 2010.
#
# ========================= *IMPORTANT* ================================
# For this method to work MRPT must be installed in your
# system in a path accesible to pkg-config. To check if pkg-config
# sees MRPT config files, execute:
# pkg-config –list-all | grep mrpt
# If no package appears, MRPT is not installed or something else is wrong.
# ======================================================================
#
# Set up basic variables:
CC = gcc
CFLAGS = -c -Wall
LDFLAGS =

# List of sources:
SOURCES = sum.c
OBJECTS = $(SOURCES:.c=.o)

# Name of executable target:
EXECUTABLE = sum

# MRPT specific flags:
# Here we invoke "pkg-config" passing it as argument the list of the
# MRPT libraries needed by our program (see available libs
# with "pkg-config –list-all | grep mrpt").
#
CFLAGS += $(shell pkg-config --cflags glib-2.0)
LDFLAGS += $(shell pkg-config --libs glib-2.0)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
