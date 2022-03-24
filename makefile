all: main server client

main:main.cpp
	g++ -g -o main main.cpp

server:server.cpp
	g++ -g -o server server.cpp

client:client.cpp
	g++ -g -o client client.cpp

clean:
	rm -rf main server client
