output: main.o board.o player.o
	g++ main.o board.o player.o -o output

main.o: main.cpp
	g++ -c main.cpp
board.o: board.cpp
	g++ -c board.cpp
player.o: player.cpp
	g++ -c player.cpp

clean:	rm *.o