
# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Omar Suárez Doro

CXX = g++                               
CXXFLAGS = -std=c++2a -g -Wall -pedantic
LDFLAGS = # The linker options (if any)     

.PHONY: all clean

all: Client

Client: ClientP11.o ProgramInterface.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@ rm -f *.o Client pepe.txt

# The $@ and $< are called automatic variables. The variable $@ represents the name 
# of the target and $< represents the first prerequisite required to create the output file.