all: main server client

main:main.cpp
	g++ -g -o main main.cpp

server:server.cpp
	g++ -g -o server server.cpp

server:server.cpp
	g++ -g -o server server.cpp

clean:
	rm -rf main server client
