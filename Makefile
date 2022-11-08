CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs -pthread

OBJECTS = Item.o Bins.o FileParser.o OfflinePacker.o OnlinePacker.o OptimalPacker.o PermutationGenerator.o


main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gc* *.dSYM test/test core main