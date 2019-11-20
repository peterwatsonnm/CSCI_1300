#makefile for Max Mad: Road warrior

#initialize compiler
CXX = g++

#Here, the variable includes the flag for all warnings
#and the one that adds debugging information
#(so that the executable can later be run under a debugger).

CXXFLAGS = -Wall -g

#targets:

MadMaxRoadWarrior: MadMaxRoadWarrior.o Player.o Car.o Engine.o Tile.o Enemy.o
	#just like g++ -Wall -g -o MadMaxRoadWarrior ......
	$(CXX) $(CXXFLAGS) -o MadMaxRoadWarrior MadMaxRoadWarrior.o Player.o Car.o Engine.o Tile.o Enemy.o
#list dependancies of all .o files
MadMaxRoadWarrior.o: MadMaxRoadWarrior.cpp Player.h Car.h Engine.h Tile.h Enemy.h
	$(CXX) $(CXXFLAGS) -c MadMaxRoadWarrior.cpp
#don't need the compilation command and the .cpp files, that was just used as an example.  MAKE can find them itself
Player.o: Player.h Car.h Engine.h
Car.o: Car.h Engine.h
Engine.o: Engine.h
Tile.o: Tile.h
Enemy.o: Enemy.h Car.h
