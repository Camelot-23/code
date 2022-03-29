# mysqlͷ�ļ����·��                                                                                                                                                                                       
MYSQLINCL = -I/usr/include/mysql
MYCPP = ./freecplus/db/mysql/_mysql.cpp

# mysql���ļ�����·��
MYSQLLIB = -L/usr/lib64/mysql

# mysql���ӿ�
MYSQLLIBS = -lmysqlclient

ORALIBS = -pthread -lm 

Gather=main server client insert

INCLUDE=-I./freecplus -I./freecplus/db/mysql

CPP=./freecplus/_freecplus.cpp

CFLAGS=-g -std=c++11 -o

all:$(Gather)

main: main.cpp
	g++ $(CFLAGS) main main.cpp $(INCLUDE) $(CPP) $(ORALIBS)

server:server.cpp
	g++ $(CFLAGS) server server.cpp $(INCLUDE) $(CPP) $(ORALIBS)

client:client.cpp
	g++ $(CFLAGS) client client.cpp $(INCLUDE) $(CPP) $(ORALIBS)

insert:insert.cpp
	g++ $(CFLAGS) insert insert.cpp $(INCLUDE) $(MYSQLINCL) $(MYSQLLIB) $(MYCPP) $(MYSQLLIBS) -lm -lc


clean:
	rm $(Gather)
