
out: main.o functions.o 
	g++ -ggdb -o out main.o functions.o

main.o: main.cpp
	g++ -ggdb -c main.cpp

functions.o: functions.cpp header.h 
	g++ -ggdb -c functions.cpp

clean:
	rm *.o out
