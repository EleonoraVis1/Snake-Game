all: game.exe

game.exe: main.cpp FoodFactory.o FoodFactory.h SnakeFactory.o SnakeFactory.h Food.o Food.h Snake.o Snake.h Factory.h Component.h
	g++ -o test.exe main.cpp Snake.o Food.o SnakeFactory.o FoodFactory.o

main.o: main.cpp Snake.h Food.h SnakeFactory.h FoodFactory.h
	g++ -c main.cpp

Snake.o: Snake.cpp Snake.h Component.h
	g++ -c Snake.cpp
	
Food.o: Food.cpp Food.h Component.h
	g++ -c Food.cpp

SnakeFactory.o: SnakeFactory.cpp Factory.h Component.h Snake.h SnakeFactory.h
	g++ -c SnakeFactory.cpp
	
FoodFactory.o: FoodFactory.cpp Factory.h Component.h Food.h FoodFactory.h
	g++ -c FoodFactory.cpp

clean:
	-del -f game.exe main.o FoodFactory.o SnakeFactory.o Food.o Snake.o
	
rebuild: clean all