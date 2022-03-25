/****************************************************************************************/
/*   ��������_cmpublic.h���˳�����freecplus��ܹ���ͷ�ļ���������Ӧ�ÿ������õ�ͷ�ļ��� */
/*   ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20190525��                              */
/*                                                                                      */
/*   freecplus��Դ����Э���������£�                                                    */
/*     ��Ȩ���� (c) 2008-2020����ũ�е���C���Լ�������www.freecplus.net����             */
/*     �ش����κεõ�����������������ĵ�������Ȩ������Ȩ����Ȩʹ�á����ơ��޸ġ�       */
/*   �ϲ������桢������ɢ��������Ȩ��/���������������ĸ����������豻��Ӧ��ͬ��        */
/*   Ȩ����ֻ�������������                                                           */
/*     �����������������и����ж�����������ϰ�Ȩ�����ͱ�����������                     */
/*     ���Υ���������ڱ�������ʹ���ϻ����������������Ƿ��漰��ͬ����������Ȩ��Ϊ��     */
/*   ���Ǳ���׷����Ȩ����                                                               */
/*   freecplus��Դ����Э�����Ľ�����                                                    */
/****************************************************************************************/

#ifndef _cmpublic_H
#define _cmpublic_H

#include <stdio.h>
#include <utime.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <errno.h>
#include <signal.h>
#include <locale.h>
#include <dirent.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>

#ifdef _WIN32
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <termios.h>
#include <netdb.h>
#endif

// ����stl��׼��������ռ�std
using namespace std;

#endif

