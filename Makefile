all: project3.exe

ColorClass.o: constant.h ColorClass.h ColorClass.cpp
	g++ -std=c++98 -g -Wall -c ColorClass.cpp -o ColorClass.o

RowColClass.o: constant.h RowColClass.h RowColClass.cpp
	g++ -std=c++98 -g -Wall -c RowColClass.cpp -o RowColClass.o

ColorImageClass.o: constant.h ColorImageClass.h ColorImageClass.cpp
	g++ -std=c++98 -g -Wall -c ColorImageClass.cpp -o ColorImageClass.o

project3.o: constant.h ColorClass.h RowColClass.h ColorImageClass.h project3.cpp
	g++ -std=c++98 -g -Wall -c project3.cpp -o project3.o

project3.exe: ColorClass.o RowColClass.o ColorImageClass.o project3.o
	g++ ColorClass.o RowColClass.o ColorImageClass.o project3.o -o project3.exe

clean:
	rm -f ColorClass.o RowColClass.o ColorImageClass.o project3.o project3.exe