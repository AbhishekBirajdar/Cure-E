# Compiler settings
CXX = g++
CXXFLAGS = -Wall -pedantic -g -std=c++11

# Build target
ev_analysis: main.o StationList.o EVStationTree.o
	$(CXX) $(CXXFLAGS) -o ev_analysis main.o StationList.o EVStationTree.o

# Compile main.cpp
main.o: StationData.h StationList.h EVStationTree.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile StationList.cpp
StationList.o: StationData.h StationList.h StationList.cpp
	$(CXX) $(CXXFLAGS) -c StationList.cpp

# Compile EVStationTree.cpp
EVStationTree.o: StationData.h EVStationTree.h EVStationTree.cpp
	$(CXX) $(CXXFLAGS) -c EVStationTree.cpp

# Clean up objects and executable
clean:
	rm -f ev_analysis ev_analysis.exe main.o StationList.o EVStationTree.o
