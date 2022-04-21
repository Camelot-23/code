#ifndef myinclude
#define myinclude 1
//Windouws/Linux 通用头文件

//C 头文件

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

//C++ 头文件

#include <iostream>
#include <regex>
#include <cstdio>
#include <vector>

#ifdef _WIN32
//Windows 头文件

#include <windows.h>
#include <direct.h>
#include <io.h>
#include <fileapi.h>
#else
//Linux 头文件

#include <unistd.h>
#endif

using namespace std;
#endif
