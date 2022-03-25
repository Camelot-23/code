/*************************************************************************
  > File Name: client.cpp
  > Author: camelot
  > Mail: 1420494366@qq.com 
  > Created Time: Thu 24 Mar 2022 01:27:34 PM CST
 ************************************************************************/

#include "_freecplus.h"

void *pth_read(void *conn);
void *pth_write(void *conn);

int main(int argc,char *argv[])
{
	CTcpClient client;

	const char ip[21] = "120.53.107.16";
	const int port = 19999;
	if(client.ConnectToServer(ip, port) == false)
	{
		perror("Connect to server failed:");
		return -1;
	}

	pthread_t pread, pwrite;
	pthread_create(&pread,  NULL, pth_read,  (void *)(long)client.m_sockfd);
	pthread_create(&pwrite, NULL, pth_write, (void *)(long)client.m_sockfd);


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

}
