ORAINCL = -I$(ORACLE_HOME)/rdbms/public                                                                                                                                                    
ORALIB =  -L$(ORACLE_HOME)/lib -L. 
ORALIBS = -pthread -lm -lc

Gather=main server client

INCLUDE=-I/home/camelot/code/freecplus -I/home/camelot/code/freecplus/db/oracle

CPP=/home/camelot/code/freecplus/_freecplus.cpp # /home/camelot/code/freecplus/db/oracle/_ooci.cpp
CFLAGS=-g -std=c++11 -o

all:$(Gather)

main: main.cpp
	g++ $(CFLAGS) main main.cpp $(INCLUDE) $(CPP) $(ORALIBS)

server:server.cpp
	g++ $(CFLAGS) server server.cpp $(INCLUDE) $(CPP) $(ORALIBS)

client:client.cpp
	g++ $(CFLAGS) client client.cpp $(INCLUDE) $(CPP) $(ORALIBS)


clean:
	rm -rf $(Gather)
