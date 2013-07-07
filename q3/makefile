#  Info:       Singally Linked List for integer datatype storage makefile
#  Created:    03.July.2013
#  Modified:   03.July.2013
#  Author:     James Muldoon

# Which compiler to use:
#	gcc		for C program
#	g++		for C++ program
CC = gcc

# Compiler flags:
#	-g 		adds debugging information to the executable file
#	-Wall	turns on most, but not all, compiler warnings
#	-I.		gcc will look in the current directory (.) for the include file(s)
CFLAGS = -I. -Wall

# The build target executable
TARGET = q3_run

# Set of .h files that the.c versions depend on.
DEPS = sll.h
# List of object files.
OBJ = q3.o sll.o

# Generate the .o file(s), compile the .c file(s) using the CC macro:
#	-c 		flag says to generate the object file
#	-o 		place the output in the file specified immediately after -o
#	$<		is the first item in the dependencies list
#	$@		says to put the left side of the :
#	$^		say to put the right side of the :
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Generate the actual executable through the use of the object files.
sll_test: $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)

# Removes the object file, backup files, core dumps, and the executable by "make clean"
clean:
	$(RM) -f *.o *~ core $(TARGET) $(TARGET).exe