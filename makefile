output: main.o game.o player.o item.o kitchen.o dungeon.o barracks.o guardedHall.o wineCellar.o theWall.o townExit.o gateExit.o
	g++ -std=c++11 main.o game.o player.o item.o kitchen.o dungeon.o barracks.o guardedHall.o wineCellar.o theWall.o townExit.o gateExit.o -o Beavs

main.o: main.cpp game.cpp game.hpp player.cpp player.hpp item.cpp item.hpp space.hpp kitchen.hpp kitchen.cpp dungeon.hpp dungeon.cpp barracks.hpp barracks.cpp guardedHall.hpp guardedHall.cpp wineCellar.hpp wineCellar.cpp theWall.cpp theWall.hpp townExit.hpp townExit.cpp gateExit.hpp gateExit.cpp
	g++ -std=c++11 -c main.cpp

game.o: game.hpp space.hpp item.hpp item.cpp player.hpp player.cpp kitchen.hpp kitchen.cpp dungeon.hpp dungeon.cpp barracks.hpp barracks.cpp guardedHall.hpp guardedHall.cpp wineCellar.hpp wineCellar.cpp theWall.cpp theWall.hpp gateExit.hpp gateExit.cpp townExit.hpp townExit.cpp 
	g++ -std=c++11 -c game.cpp

player.o: player.hpp player.cpp item.hpp item.cpp 
	g++ -std=c++11 -c player.cpp 
	
item.o: item.hpp item.cpp 
	g++ -std=c++11 -c item.cpp 
	
theWall.o: space.hpp theWall.hpp theWall.cpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c theWall.cpp

townExit.o: space.hpp townExit.hpp townExit.cpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c townExit.cpp

gateExit.o: gateExit.hpp gateExit.cpp space.hpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c gateExit.cpp

kitchen.o: space.hpp kitchen.hpp kitchen.cpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c kitchen.cpp

dungeon.o: space.hpp dungeon.hpp dungeon.cpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c dungeon.cpp

barracks.o: space.hpp barracks.hpp barracks.cpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c barracks.cpp

guardedHall.o: space.hpp guardedHall.hpp guardedHall.cpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c guardedHall.cpp

wineCellar.o: space.hpp wineCellar.hpp wineCellar.cpp item.cpp item.hpp player.hpp player.cpp
	g++ -std=c++11 -c wineCellar.cpp

clean:
	rm *.o output
