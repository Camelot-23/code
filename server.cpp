/*************************************************************************
  > File Name: server.cpp
  > Author: camelot
  > Mail: 1420494366@qq.com 
  > Created Time: Thu 24 Mar 2022 12:23:02 PM CST
 ************************************************************************/

#include "_freecplus.h"

void EXIT(int sig);
void *pth_read(void *conn);
void *pth_write(void *conn);
int SocketConnected(int sock);


int main(int argc,char *argv[])
{
	signal(SIGINT, EXIT);
	CTcpServer server;

	const int port = 19999;
	if(server.InitServer(port) == false)
	{
		perror("Init server failed:");
		return -1;
	}

	if(server.Accept() == false)
	{
		perror("Server accept failed!\n");
		return -1;
	}

	printf("Client IP:%s\n", server.GetIP());

	pthread_t pread, pwrite;
	pthread_create(&pread,  NULL, pth_read ,(void *)(long)server.m_connfd);
	pthread_create(&pwrite, NULL, pth_write,(void *)(long)server.m_connfd);


	pthread_join(pread, NULL);
	pthread_join(pwrite, NULL);
	return 0;
}
void *pth_read(void *conn)
{
	int sock = (long)conn;
	char Rbuffer[1001];
	int bsize = sizeof(Rbuffer);

	while(true)
	{
		memset(Rbuffer, 0, sizeof(Rbuffer));
		if(TcpRead(sock, Rbuffer, &bsize) == false)
			break;
		printf("read:%s\n", Rbuffer);
		if(strcmp(Rbuffer, "bye") == 0)
		{
			TcpWrite(sock, "bye");
			break;
		}
	}

	pthread_exit(0);
}

void *pth_write(void *conn)
{    
	int sock = (long)conn;

	char Wbuffer[1001];
	int bsize = sizeof(Wbuffer);

	while(true)
	{   
		memset(Wbuffer, 0, sizeof(Wbuffer));
		scanf("%s", Wbuffer);
		if(TcpWrite(sock, Wbuffer) == false)
			break;
		if(strcmp(Wbuffer, "bye") == 0)
			break;
	}
	pthread_exit(0);
}

void EXIT(int sig)
{
	printf("catch the signal %d, program exit!\n", sig);
	exit(0);
}
