all: main

main:main.cpp
	g++ -g -o main main.cpp

clean:
	rm -rf main
