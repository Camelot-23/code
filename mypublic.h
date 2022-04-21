#ifndef __MYPUBLIC_H
#define __MYPUBLIC_H 1

#include "myinclude.h"

//删除字符串左边指定数量的指定字符
//str  为目标字符串
//chr  为目标字符
//size 为要求删除的数量，为负数时删除左边全部的指定字符，为0时不删除，为正数时删除指定数量
int DeleteLChar(char* str, char chr, int size = -1);

//删除字符串右边指定数量的指定字符
//str  为目标字符串
//chr  为目标字符
//size 为要求删除的数量，为负数时删除右边全部的指定字符，为0时不删除，为正数时删除指定数量
int DeleteRChar(char* str, char chr, int size = -1);

//同时删除一个字符串左右两边的所有指定字符
void DeleteLRChar(char* str, char chr);

//删除字符串左边某个字符之前的所有字符
//str  为目标字符转
//chr  为目标字符
//sef  是否删除目标字符本身
int DeleteLAllChar(char* str, char chr, bool sef = false);

//删除字符串右边边某个字符之后的所有字符
//str  为目标字符转
//chr  为目标字符
//sef  是否删除目标字符本身
int DeleteRAllChar(char* str, char chr, bool sef = false);

//正则匹配一个字符串
//str  为待匹配的字符串
//rule 为匹配规则
//bool MatchStr(const char* str, const char* rule);
//正则匹配一个字符串
//str  为待匹配的字符串
//rule 为匹配规则
bool MatchStr(string str, string rule);

#define FILE_NAME_LENGTH 255

//文本文件读写类
class File
{
private:
	FILE* m_fp;//文件指针
	char m_filename[FILE_NAME_LENGTH+1];//文件名

public:
	//构造函数
	File();

	//构析函数
	~File();

	//打开文件
	//filename 文件名
	//openmode 打开文件的方式，默认为 "r"
	bool Open(const char* filename, const char* openmode = "r");

	//从文件中读取以指定字符结尾的一行
	//buffer 接受字符串的缓冲区
	//rsize  缓冲区的大小，最多写入的字节数，即应该为sizeof(buffer)-1
	//chr    结尾字符，默认为 \n
	//delchr 是否删除换行符，默认不删除
	bool Fgets(char* buffer, int rsize, const char chr = '\n', bool delchr = false);

	// 调用fread从文件中读取数据。
	size_t Fread(void* ptr, size_t size);

	// 调用fwrite向文件中写数据
	size_t Fwrite(const void* ptr, size_t size);

	//关闭文件
	void Close();
};

class Dir
{
//private:
public:
	char m_DirName[256]; // 需要操作的目标目录名，可以为相对路径或绝对路径
	char m_Npath[256];   // 程序运行的绝对路径
	char m_Fpath[256];   // 上级目录绝对路径

	char m_FileName[256];     //文件名
	char m_FullFileName[256]; //文件全路径名
	char m_Path[256];         // 文件目录
	int  m_FileSize;          // 文件大小，单位字节

	int pos = 0; // 记录当前读取文件在容器中的位置

	vector<string> m_vFileName; // 已获取到的绝对路径文件名清单

	Dir();

	//打开目录
	//DirName   目录名
	//MathStr   文件名的匹配规则，采用正则匹配，默认为 ".*"
	//MaxCount  获取文件的最大数量，默认为10000
	//AndChirld 是否递归的打开子目录
	//Sort      是否对文件名进行排序，默认为false
	bool OpenDir(const char* DirName, const char* MathStr = ".*", const unsigned int MaxCount = 10000, const bool AndChirld = false, bool Sort = false);

	//用于被OpenDir调用，仅接收绝对路径值
	bool _OpenDir(const char* DirName, const char* MathStr, const unsigned int MaxCount, const bool AndChirld);

	//读取一条文件信息
	bool ReadDir();

	~Dir();
};

//根据 文件名/目录名 逐级创建目录
//filename 文件名/目录名
//isfile   filename是否为文件？ 默认为false
//注意：在Windows下，当前目录下有同名的文件存在时，创建会失败
bool MKDIR(const char* filename, bool isfile = false);

//打开/新建 一个文件，如果新建时存放它的目录不存在，那么会逐级的创建它们 
FILE* FOPEN(const char* filename, const char* openmode);

bool RENAME(const char* file);




// CCmdStr类用于拆分有分隔符的字符串。
// 字符串的格式为：字段内容1+分隔符+字段内容2+分隔符+字段内容3+分隔符+...+字段内容n。
// 例如："messi,10,striker,30,1.72,68.5,Barcelona"，这是足球运动员梅西的资料，包括姓名、
// 球衣号码、场上位置、年龄、身高、体重和效力的俱乐部，字段之间用半角的逗号分隔。
class CCmdStr
{
public:
	vector<string> m_vCmdStr;  // 存放拆分后的字段内容。

	CCmdStr();  // 构造函数。

	// 把字符串拆分到m_vCmdStr容器中。
	// buffer：待拆分的字符串。
	// sepstr：buffer中采用的分隔符，注意，sepstr参数的数据类型不是字符，是字符串，如","、" "、"|"、"~!~"。
	// bdelspace：拆分后是否删除字段内容前后的空格，true-删除；false-不删除，缺省删除。
	void SplitToCmd(const string buffer, const char* sepstr, const bool bdelspace = true);

	// 获取拆分后字段的个数，即m_vCmdStr容器的大小。
	int CmdCount();

	// 从m_vCmdStr容器获取字段内容。
	// inum：字段的顺序号，类似数组的下标，从0开始。
	// value：传入变量的地址，用于存放字段内容。
	// 返回值：true-成功；如果inum的取值超出了m_vCmdStr容器的大小，返回失败。
	bool GetValue(const int inum, char* value, const int ilen = 0); // 字符串，ilen缺省值为0。
	bool GetValue(const int inum, int* value); // int整数。
	bool GetValue(const int inum, unsigned int* value); // unsigned int整数。
	bool GetValue(const int inum, long* value); // long整数。
	bool GetValue(const int inum, unsigned long* value); // unsigned long整数。
	bool GetValue(const int inum, double* value); // 双精度double。
	bool GetValue(const int inum, bool* value); // bool型。

	~CCmdStr(); // 析构函数。
};


#endif // !__MYPUBLIC_H


