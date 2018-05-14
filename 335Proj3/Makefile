# A makefile that can be used for a generic C++ project in which there is
# a single executable named project3, which depends on all source code files.
# To build or update the executable, or any files that require rebuilding,
# type
#     make
# To remove object files only, type
#     make clean
# To remove object files and the executable, type 
#     make cleanall
#
# Written by Stewart Weiss for CSci 335, Spring 2018, Project 3
# Modified (heavily) by Kaizen Castanos

CXX       := /usr/bin/g++
CXXFLAGS  += -Wall -g -lm -std=c++11

all: project3

run: 
	./project3 subway_entrances_cleaned.csv commandfile2

.PHONY: clean  cleanall
clean:
	rm -f $(OBJS) 

cleanall:
	rm -f $(OBJS) $(PROG) 

project3: subway_entrance.o subway_station.o subway_system.o command.o main.o
	$(CXX) $(CXXFLAGS) -o project3 subway_entrance.o subway_station.o subway_system.o command.o main.o

main.o: main.cpp subway_entrance.h subway_station.h subway_system.h command.h
	$(CXX) $(CXXFLAGS) -c main.cpp

subway_system.o: subway_system.cpp subway_system.h subway_station.h subway_entrance.h haversine.h
	$(CXX) $(CXXFLAGS) -c subway_system.cpp

subway_station.o: subway_station.cpp subway_station.h subway_entrance.h
	$(CXX) $(CXXFLAGS) -c subway_station.cpp

subway_entrance.o: subway_entrance.cpp subway_entrance.h
	$(CXX) $(CXXFLAGS) -c subway_entrance.cpp


move:
	cp *.h temp_final
	cp *.cpp temp_final
	cp README temp_final
