#include "mypublic.h"

int DeleteLChar(char* str, char chr, int size)
{
	if (str == NULL) return -1;
	if (strlen(str) == 0) return -1;
	if (size == 0) return -1;

	size_t strsize = strlen(str);
	char* TempStr = (char*)malloc(strsize + 1);
	if (TempStr == NULL) return -1;
	memset(TempStr, 0, strsize + 1);

	strcpy(TempStr, str);
	int i = 0;
	while (TempStr[i] == chr)
	{
		if (i == size)
			break;
		i++;
	}
	memset(str, 0, strlen(str) + 1);
	strcpy(str, TempStr + i);

	free(TempStr);
	return 0;
}

int DeleteLAllChar(char* str, char chr, bool sef)
{
	if (str == NULL) return -1;
	if (chr == '\0') return -1;
	if (strlen(str) == 0) return -1;

	size_t strsize = strlen(str);
	char* TempStr = (char*)malloc(strsize + 1);
	if (TempStr == NULL) return -1;
	memset(TempStr, 0, strsize + 1);
	strcpy(TempStr, str);

	int i = 0;
	int length = (int)strlen(str);
	while (TempStr[i] != chr)
	{
		if (i == strsize - 1)
			break;
		i++;
	}

	if (sef == true)
		i++;
	memset(str, 0, strsize + 1);
	strcpy(str, TempStr + i);

	return 0;
}

int DeleteRAllChar(char* str, char chr, bool sef)
{
	if (str == NULL) return -1;
	if (strlen(str) == 0) return -1;

	int i = 0;
	int length = (int)strlen(str);
	while ((str[length - i - 1] != chr) && ((length - i -1 ) >= 0))
	{
		str[length - i - 1] = 0;
		i++;
	}
	if (sef == true)
		i++;
	str[length - i] = '\0';

	return 0;
}

int DeleteRChar(char* str, char chr, int size)
{
	if (str == NULL) return -1;
	if (strlen(str) == 0) return -1;
	if (size == 0) return -1;

	int i = 0;
	int length = (int)strlen(str);
	while (str[length - i - 1] == chr)
	{
		str[length - i - 1] = 0;
		i++;
		if (i == size)
			break;
	}
	str[length - i] = '\0';

	return 0;
}

void DeleteLRChar(char* str, char chr)
{
	DeleteLChar(str, chr);
	DeleteRChar(str, chr);
}

bool MatchStr(string str, string rule)
{
	CCmdStr md;
	md.SplitToCmd(rule, ",");
	bool x = false;

	for (int i = 0; i < md.m_vCmdStr.size(); i++)
	{
		regex reg(md.m_vCmdStr[i].c_str());
		x = regex_match(str, reg);
		if (x == true)
			break;
	}

	return x;
}
File::File()
{
	m_fp = NULL;
	memset(m_filename, 0, sizeof(m_filename));
}
File::~File()
{
	Close();
}
bool File::Open(const char* filename, const char* openmode)
{
	Close();

	if ((m_fp = FOPEN(filename, openmode)) == 0)
		return false;

	memset(m_filename, 0, FILE_NAME_LENGTH);
	m_filename[FILE_NAME_LENGTH] = '\0';
	strncpy(m_filename, filename, FILE_NAME_LENGTH);

	return true;
}
bool File::Fgets(char* buffer, int rsize, const char chr, bool delchr)
{
	if (m_fp == NULL) return false;
	if (rsize == 0) return false;

	memset(buffer, 0, rsize);
	buffer[rsize] = '\0';
	char c = 0;
	int step = 0;
	while (rsize > 0)
	{
		//读到文件末尾时返回0
		if (fread(&c, 1, 1, m_fp) == 0)
		{
			break;
		}
		buffer[step++] = c;
		if (c == chr)
			break;
		rsize--;
	}
	if (step == 0)
		return false;
	//添加字符串结束符
	buffer[step] = '\0';
	//删除结尾符
	if (delchr == true)
	{
		DeleteRChar(buffer, chr, 1);
	}
	return true;
}
// 调用fread从文件中读取数据。
size_t File::Fread(void* ptr, size_t size)
{
	if (m_fp == 0) return -1;

	return fread(ptr, 1, size, m_fp);
}

// 调用fwrite向文件中写数据
size_t File::Fwrite(const void* ptr, size_t size)
{
	if (m_fp == 0) return -1;

	size_t tt = fwrite(ptr, 1, size, m_fp);

	return tt;
}

void File::Close()
{
	if (m_fp != NULL)
		fclose(m_fp);
}

//文件操作类结束

#ifdef _WIN32
//目录操作类开始

// 构造
Dir::Dir()
{
	memset(m_DirName, 0,256);
	memset(m_Npath, 0, 256);
	memset(m_Fpath, 0, 256);
	memset(m_FileName, 0, 256);
	memset(m_FullFileName, 0, 256);

	char *c = getcwd(m_Npath, 255);
	strcpy(m_Fpath, m_Npath);
	DeleteRAllChar(m_Fpath, '\\', true);
	//printf("m_Npath:%s\n", m_Npath);
	//printf("m_FPath:%s\n", m_Fpath);
}

bool Dir::OpenDir(const char* DirName, const char* Mathstr, const unsigned int MaxCount, const bool AndChirld, bool Sort)
{
	char argdir[256];
	memset(argdir, 0, sizeof(argdir));

	if (DirName[0] == '.')
	{
		if (DirName[1] == '.')
		{
			//从父目录开始
			strcpy(argdir, m_Fpath);
		}
		else
		{
			//从当前目录开始
			strcpy(argdir, m_Npath);
		}
	}
	//绝对路径
	else if(DirName[1] == ':')
	{
		strcpy(argdir, DirName);
	}
	//从当前目录下开始
	else
	{
		strcpy(argdir, m_Npath);
		strcat(argdir, "\\");
		strcat(argdir, DirName);
	}
#ifdef _WIN32
	if (_access(argdir, 0) != 0)
#else
	if (access(argdir, 0) != 0)
#endif
		return false;

	_OpenDir(argdir, Mathstr, MaxCount, AndChirld);

	if (Sort == true)
	{
		sort(m_vFileName.begin(), m_vFileName.end());
	}

	return true;
}

bool Dir::_OpenDir(const char* DirName, const char* Mathstr, const unsigned int MaxCount, const bool AndChirld)
{
	WIN32_FIND_DATA p; // 文件属性
	HANDLE h; // 查找句柄

	char dirname[256];
	memset(dirname, 0, sizeof(dirname));
	dirname[255] = '\0';

	strcpy(dirname, DirName);
	strcat(dirname, "\\*");

	//第一个文件是.
	h = FindFirstFile(dirname, &p);

	//非法目录时返回
	if ((int)h == -1)
		return false;

	//第二个文件是..
	FindNextFile(h, &p);
	while (FindNextFile(h, &p))
	{
		//达到最大文件数时退出
		if (m_vFileName.size() == MaxCount)
			return true;
		if (p.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (AndChirld == true)
			{
				char tempstr[256];
				memset(tempstr, 0, sizeof(tempstr));
				sprintf(tempstr, "%s\\%s", DirName, p.cFileName);
				_OpenDir(tempstr, Mathstr, MaxCount, AndChirld);
			}
		}
		else
		{
			if (MatchStr(p.cFileName, Mathstr) == true)
			{
				char tempfilename[256];
				memset(tempfilename, 0, sizeof(tempfilename));

				sprintf(tempfilename, "%s\\%s", DirName, p.cFileName);
				string name = tempfilename;
				m_vFileName.push_back(name);
				//printf("%s\n", name.c_str());
			}
		}
	}

	return true;
}

bool Dir::ReadDir()
{
	//已经读完了就返回失败
	if (pos == m_vFileName.size())
		return false;

	//取全路径名
	strcpy(m_FullFileName ,m_vFileName[pos++].c_str());

	int i = strlen(m_FullFileName);
	while (i >= 0)
	{
		if (m_FullFileName[i] == '\\')
			break;
		i--;
	}
	i++;
	//取文件名
	strcpy(m_FileName, m_FullFileName + i);
	strcpy(m_Path, m_FullFileName);
	DeleteRAllChar(m_Path, '\\', true);

	struct _stat info;
	_stat(m_FullFileName, &info);
	m_FileSize = info.st_size;

	return true;
}



// 构析
Dir::~Dir()
{
	m_vFileName.clear();
}

//目录操作类结束
#else
#endif
bool MKDIR(const char* filename, bool isfile)
{
	if (filename == NULL) return false;
	if (strlen(filename) == 0) return false;
	if ((strlen(filename) == 1) && (filename[0] == '/')) return false;

	char PathName[301];
	int flen = (int)strlen(filename);

	//逐级创建目录
	for (int i = 1; i < flen; i++)
	{
		if (filename[i] != '/') continue;

		memset(PathName, 0, sizeof(PathName));
		strncpy(PathName, filename, i);
		PathName[i] = '\0';

#ifdef _WIN32
		if (_access(PathName, 0) == 0) continue;
		if (_mkdir(PathName) == -1)
#else
		if (access(PathName, 0) == 0) continue;
		if (mkdir(PathName, 755) == -1)
#endif
			return false;
	}
	if (isfile == false)
#ifdef _WIN32
		if (_access(filename, 0) != 0)
			if (_mkdir(filename) == -1)
#else
		if (access(filename, 0) != 0)
			if (mkdir(filename, 755) == -1)
#endif
				return false;
	return true;
}

FILE* FOPEN(const char* filename, const char* openmode)
{
	if (MKDIR(filename, true) == false)
		return NULL;

	return fopen(filename, openmode);
}














CCmdStr::CCmdStr()
{
	m_vCmdStr.clear();
}

// 把字符串拆分到m_vCmdStr容器中。
// buffer：待拆分的字符串。
// sepstr：buffer字符串中字段内容的分隔符，注意，分隔符是字符串，如","、" "、"|"、"~!~"。
// bdelspace：是否删除拆分后的字段内容前后的空格，true-删除；false-不删除，缺省删除。
void CCmdStr::SplitToCmd(const string buffer, const char* sepstr, const bool bdelspace)
{
	// 清除所有的旧数据
	m_vCmdStr.clear();

	int iPOS = 0;
	string srcstr, substr;

	srcstr = buffer;

	char str[2048];

	while ((iPOS = srcstr.find(sepstr)) >= 0)
	{
		substr = srcstr.substr(0, iPOS);

		if (bdelspace == true)
		{
			memset(str, 0, sizeof(str));

			strncpy(str, substr.c_str(), 2000);

			DeleteLRChar(str, ' ');

			substr = str;
		}

		m_vCmdStr.push_back(substr);

		iPOS = iPOS + strlen(sepstr);

		srcstr = srcstr.substr(iPOS, srcstr.size() - iPOS);

	}

	substr = srcstr;

	if (bdelspace == true)
	{
		memset(str, 0, sizeof(str));

		strncpy(str, substr.c_str(), 2000);

		DeleteLRChar(str, ' ');

		substr = str;
	}

	m_vCmdStr.push_back(substr);

	return;
}

int CCmdStr::CmdCount()
{
	return m_vCmdStr.size();
}

bool CCmdStr::GetValue(const int inum, char* value, const int ilen)
{
	if ((inum >= (int)m_vCmdStr.size()) || (value == 0)) return false;

	if (ilen > 0) memset(value, 0, ilen + 1);   // 调用者必须保证value的空间足够，否则这里会内存溢出。

	if ((m_vCmdStr[inum].length() <= (unsigned int)ilen) || (ilen == 0))
	{
		strcpy(value, m_vCmdStr[inum].c_str());
	}
	else
	{
		strncpy(value, m_vCmdStr[inum].c_str(), ilen); value[ilen] = 0;
	}

	return true;
}

bool CCmdStr::GetValue(const int inum, int* value)
{
	if ((inum >= (int)m_vCmdStr.size()) || (value == 0)) return false;

	(*value) = 0;

	if (inum >= (int)m_vCmdStr.size()) return false;

	(*value) = atoi(m_vCmdStr[inum].c_str());

	return true;
}

bool CCmdStr::GetValue(const int inum, unsigned int* value)
{
	if ((inum >= (int)m_vCmdStr.size()) || (value == 0)) return false;

	(*value) = 0;

	if (inum >= (int)m_vCmdStr.size()) return false;

	(*value) = atoi(m_vCmdStr[inum].c_str());

	return true;
}


bool CCmdStr::GetValue(const int inum, long* value)
{
	if ((inum >= (int)m_vCmdStr.size()) || (value == 0)) return false;

	(*value) = 0;

	if (inum >= (int)m_vCmdStr.size()) return false;

	(*value) = atol(m_vCmdStr[inum].c_str());

	return true;
}

bool CCmdStr::GetValue(const int inum, unsigned long* value)
{
	if ((inum >= (int)m_vCmdStr.size()) || (value == 0)) return false;

	(*value) = 0;

	if (inum >= (int)m_vCmdStr.size()) return false;

	(*value) = atol(m_vCmdStr[inum].c_str());

	return true;
}

bool CCmdStr::GetValue(const int inum, double* value)
{
	if ((inum >= (int)m_vCmdStr.size()) || (value == 0)) return false;

	(*value) = 0;

	if (inum >= (int)m_vCmdStr.size()) return false;

	(*value) = (double)atof(m_vCmdStr[inum].c_str());

	return true;
}

bool CCmdStr::GetValue(const int inum, bool* value)
{
	if ((inum >= (int)m_vCmdStr.size()) || (value == 0)) return false;

	(*value) = 0;

	if (inum >= (int)m_vCmdStr.size()) return false;

	char strTemp[11];
	memset(strTemp, 0, sizeof(strTemp));
	strncpy(strTemp, m_vCmdStr[inum].c_str(), 10);

	//ToUpper(strTemp);  // 转换为大写来判断。
	if (strcmp(strTemp, "TRUE") == 0) (*value) = true;

	return true;
}

CCmdStr::~CCmdStr()
{
	m_vCmdStr.clear();
}

