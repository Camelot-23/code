ORALIBS = -pthread -lm 

Gather=main server client

INCLUDE=-I./freecplus

CPP=./freecplus/_freecplus.cpp
CFLAGS=-g -std=c++11 -o

all:$(Gather)

main: main.cpp
	g++ $(CFLAGS) main main.cpp $(INCLUDE) $(CPP) $(ORALIBS)

server:server.cpp
	g++ $(CFLAGS) server server.cpp $(INCLUDE) $(CPP) $(ORALIBS)

client:client.cpp
	g++ $(CFLAGS) client client.cpp $(INCLUDE) $(CPP) $(ORALIBS)


clean:
	rm $(Gather)
