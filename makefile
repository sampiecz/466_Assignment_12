#
# PROGRAM: Assign 12  
# PROGRAMMER: Samuel Piecz 
# LOGON ID: Z1732715 
# DATE DUE: 05/04/18 
#
# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment12: assignment12.o
	g++ $(CCFLAGS) -o assignment12.exe assignment12.o

# Rule to compile source code file to object code
assignment12.o: assignment12.cc
	g++ $(CCFLAGS) -c assignment12.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm -f *.o assignment12.exe
