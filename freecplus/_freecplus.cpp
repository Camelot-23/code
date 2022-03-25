/****************************************************************************************/
/*   ��������_freecplus.h���˳�����freecplus��ܹ��ú�������Ķ����ļ���                */
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

#include "_freecplus.h"  

// ��ȫ��strcpy������
// dest��Ŀ���ַ���������Ҫ��ʼ������STRCPY�������г�ʼ�����롣
// destlen��Ŀ���ַ���destռ���ڴ�Ĵ�С��
// src��ԭ�ַ�����
// ����ֵ��Ŀ���ַ���dest�ĵ�ַ��
char *STRCPY(char* dest,const size_t destlen,const char* src)
{
  if (dest==0) return 0;
  memset(dest,0,destlen);   // ��ʼ��dest��
  if (src==0) return dest;

  if (strlen(src)>destlen-1) strncpy(dest,src,destlen-1); 
  else strcpy(dest,src);

  return dest;
}

// ��ȫ��strncpy������
// dest��Ŀ���ַ���������Ҫ��ʼ������STRCPY�������г�ʼ�����롣
// destlen��Ŀ���ַ���destռ���ڴ�Ĵ�С��
// src��ԭ�ַ�����
// n�������Ƶ��ֽ�����
// ����ֵ��Ŀ���ַ���dest�ĵ�ַ��
char *STRNCPY(char* dest,const size_t destlen,const char* src,size_t n)
{
  if (dest==0) return 0;
  memset(dest,0,destlen);   // ��ʼ��dest��
  if (src==0) return dest;

  if (n>destlen-1) strncpy(dest,src,destlen-1); 
  else strncpy(dest,src,n);

  return dest;
}

// ��ȫ��strcat������
// dest��Ŀ���ַ�����ע�⣬���dest��δʹ������ô��Ҫ����һ�γ�ʼ����
// destlen��Ŀ���ַ���destռ���ڴ�Ĵ�С��
// src����׷���ַ�����
// ����ֵ��Ŀ���ַ���dest�ĵ�ַ��
char *STRCAT(char* dest,const size_t destlen,const char* src)
{
  if (dest==0) return 0;
  if (src==0) return dest;

  unsigned int left=destlen-1-strlen(dest);

  if (strlen(src)>left) { strncat(dest,src,left); dest[destlen-1]=0; }
  else strcat(dest,src);

  return dest;
}

// ��ȫ��strncat������
// dest��Ŀ���ַ�����ע�⣬���dest��δʹ������ô��Ҫ����һ�γ�ʼ����
// destlen��Ŀ���ַ���destռ���ڴ�Ĵ�С��
// src����׷���ַ�����
// n����׷�ӵ��ֽ�����
// ����ֵ��Ŀ���ַ���dest�ĵ�ַ��
char *STRNCAT(char* dest,const size_t destlen,const char* src,size_t n)
{
  if (dest==0) return 0;
  if (src==0) return dest;

  size_t left=destlen-1-strlen(dest);

  if (n>left) { strncat(dest,src,left); dest[destlen-1]=0; }
  else strncat(dest,src,n);

  return dest;
}

// ��ȫ��sprintf������
// ���ɱ����(...)����fmt�����ĸ�ʽ�����dest�ַ����С�
// dest������ַ���������Ҫ��ʼ������SPRINTF�����л�������г�ʼ����
// destlen������ַ���destռ���ڴ�Ĵ�С�������ʽ������ַ������ݵĳ��ȴ���destlen-1����������ݽ�������
// fmt����ʽ����������
// ...����䵽��ʽ��������fmt�еĲ�����
// ����ֵ����ʽ��������ݵĳ��ȣ�����Աһ�㲻���ķ���ֵ��
int SPRINTF(char *dest,const size_t destlen,const char *fmt,...)
{
  if (dest==0) return -1;

  memset(dest,0,destlen);

  va_list arg;
  va_start(arg,fmt);
  vsnprintf(dest,destlen,fmt,arg );
  va_end(arg);

  return strlen(dest);
}

// ��ȫ��snprintf������
// ���ɱ����(...)����fmt�����ĸ�ʽ�����dest�ַ����С�
// dest������ַ���������Ҫ��ʼ������SNPRINTF�����л�������г�ʼ����
// destlen������ַ���destռ���ڴ�Ĵ�С�������ʽ������ַ������ݵĳ��ȴ���destlen-1����������ݽ�������
// n���Ѹ�ʽ������ַ�����ȡn-1��ŵ�dest�У����n>destlen����ȡdestlen-1��
// fmt����ʽ����������
// ...����䵽��ʽ��������fmt�еĲ�����
// ����ֵ����ʽ��������ݵĳ��ȣ�����Աһ�㲻���ķ���ֵ��
int SNPRINTF(char *dest,const size_t destlen,size_t n,const char *fmt,...)
{
  if (dest==0) return -1;

  memset(dest,0,destlen);

  int len=n;
  if (n>destlen) len=destlen;

  va_list arg;
  va_start(arg,fmt);
  vsnprintf(dest,len,fmt,arg );
  va_end(arg);

  return strlen(dest);
}

// ɾ���ַ������ָ�����ַ���
// str�����������ַ�����
// chr����Ҫɾ�����ַ���
void DeleteLChar(char *str,const char chr)
{
  if (str == 0) return;
  if (strlen(str) == 0) return;

  char strTemp[strlen(str)+1];

  int iTemp=0;

  memset(strTemp,0,sizeof(strTemp));
  strcpy(strTemp,str);

  while ( strTemp[iTemp] == chr )  iTemp++;

  memset(str,0,strlen(str)+1);

  strcpy(str,strTemp+iTemp);

  return;
}

// ɾ���ַ����ұ�ָ�����ַ���
// str�����������ַ�����
// chr����Ҫɾ�����ַ���
void DeleteRChar(char *str,const char chr)
{
  if (str == 0) return;
  if (strlen(str) == 0) return;

  int istrlen = strlen(str);

  while (istrlen>0)
  {
    if (str[istrlen-1] != chr) break;

    str[istrlen-1]=0;

    istrlen--;
  }
}

// ɾ���ַ�����������ָ�����ַ���
// str�����������ַ�����
// chr����Ҫɾ�����ַ���
void DeleteLRChar(char *str,const char chr)
{
  DeleteLChar(str,chr);
  DeleteRChar(str,chr);
}

// ���ַ����е�Сд��ĸת���ɴ�д�����Բ�����ĸ���ַ���
// str����ת�����ַ�����֧��char[]��string�������͡�
void ToUpper(char *str)
{
  if (str == 0) return;

  if (strlen(str) == 0) return;

  int istrlen=strlen(str);

  for (int ii=0;ii<istrlen;ii++)
  {
    if ( (str[ii] >= 'a') && (str[ii] <= 'z') ) str[ii]=str[ii] - 32;
  }
}

void ToUpper(string &str)
{
  if (str.empty()) return;

  char strtemp[str.size()+1];

  memset(strtemp,0,sizeof(strtemp));
  strcpy(strtemp,str.c_str());

  ToUpper(strtemp);

  str=strtemp;

  return;
}

// ���ַ����еĴ�д��ĸת����Сд�����Բ�����ĸ���ַ���
// str����ת�����ַ�����֧��char[]��string�������͡�
void ToLower(char *str)
{
  if (str == 0) return;

  if (strlen(str) == 0) return;

  int istrlen=strlen(str);

  for (int ii=0;ii<istrlen;ii++)
  {
    if ( (str[ii] >= 'A') && (str[ii] <= 'Z') ) str[ii]=str[ii] + 32;
  }
}

void ToLower(string &str)
{
  if (str.empty()) return;

  char strtemp[str.size()+1];

  memset(strtemp,0,sizeof(strtemp));
  strcpy(strtemp,str.c_str());

  ToLower(strtemp);

  str=strtemp;

  return;
}

// �ַ����滻����
// ���ַ���str�У���������ַ���str1�����滻Ϊ�ַ���str2��
// str�����������ַ�����
// str1���ɵ����ݡ�
// str2���µ����ݡ�
// bloop���Ƿ�ѭ��ִ���滻��
// ע�⣺
// 1�����str2��str1Ҫ�����滻��str��䳤�����Ա��뱣֤str���㹻�ĳ��ȣ������ڴ�������
// 2�����str2�а�����str1�����ݣ���bloopΪtrue�������߼����󣬽���ִ���κ��滻��
void UpdateStr(char *str,const char *str1,const char *str2,bool bloop)
{
  if (str == 0) return;
  if (strlen(str) == 0) return;
  if ( (str1 == 0) || (str2 == 0) ) return;

  // ���bloopΪtrue����str2�а�����str1�����ݣ�ֱ�ӷ��أ���Ϊ�������ѭ�������յ����ڴ������
  if ( (bloop==true) && (strstr(str2,str1)>0) ) return;

  // �����ܷ������Ŀռ䣬�����п��ܳ����ڴ���������������Ż���string��
  int ilen=strlen(str)*10;
  if (ilen<1000) ilen=1000;

  char strTemp[ilen];

  char *strStart=str;

  char *strPos=0;

  while (true)
  {
    if (bloop == true)
    {
      strPos=strstr(str,str1);
    }
    else
    {
      strPos=strstr(strStart,str1);
    }

    if (strPos == 0) break;

    memset(strTemp,0,sizeof(strTemp));
    strncpy(strTemp,str,strPos-str);
    strcat(strTemp,str2);
    strcat(strTemp,strPos+strlen(str1));
    strcpy(str,strTemp);

    strStart=strPos+strlen(str2);
  }
}

// ��һ���ַ�������ȡ�����ֵ����ݣ���ŵ���һ���ַ����С�
// src��Դ�ַ�����
// dest��Ŀ���ַ�����
// bsigned���Ƿ�������ţ�+��-����true-������false-��������
// bdot���Ƿ����С�����Բ����ţ�true-������false-��������
void PickNumber(const char *src,char *dest,const bool bsigned,const bool bdot)
{
  if (dest==0) return;
  if (src==0) { strcpy(dest,""); return; }

  char strtemp[strlen(src)+1];
  memset(strtemp,0,sizeof(strtemp));
  strcpy(strtemp,src);
  DeleteLRChar(strtemp,' ');

  int ipossrc,iposdst,ilen;
  ipossrc=iposdst=ilen=0;

  ilen=strlen(strtemp);

  for (ipossrc=0;ipossrc<ilen;ipossrc++)
  {
    if ( (bsigned==true) && (strtemp[ipossrc] == '+') )
    {
      dest[iposdst++]=strtemp[ipossrc]; continue;
    }

    if ( (bsigned==true) && (strtemp[ipossrc] == '-') )
    {
      dest[iposdst++]=strtemp[ipossrc]; continue;
    }

    if ( (bdot==true) && (strtemp[ipossrc] == '.') )
    {
      dest[iposdst++]=strtemp[ipossrc]; continue;
    }

    if (isdigit(strtemp[ipossrc])) dest[iposdst++]=strtemp[ipossrc];
  }

  dest[iposdst]=0;
}

// �������ʽ���ж�һ���ַ����Ƿ�ƥ����һ���ַ�����
// str����Ҫ�жϵ��ַ�������ȷ��ʾ���ַ��������ļ���"freecplus.cpp"��
// rules��ƥ��������ʽ�����Ǻ�"*"��ʾ�����ַ���������ַ���֮���ð�ǵĶ��ŷָ�����"*.h,*.cpp"��
// ע�⣬str������֧��"*"��rules����֧��"*"���������ж�str�Ƿ�ƥ��rules��ʱ�򣬻������ĸ�Ĵ�Сд��
bool MatchStr(const string str,const string rules)
{
  // ������ڱȽϵ��ַ��ǿյģ�����false
  if (rules.size() == 0) return false;

  // ������Ƚϵ��ַ�����"*"������true
  if (rules == "*") return true;

  // �����ļ���ƥ������е�ʱ��ƥ��dd-nn.mm
  char strTemp[2049];
  memset(strTemp,0,sizeof(strTemp));
  strncpy(strTemp,rules.c_str(),2000);

  int ii,jj;
  int  iPOS1,iPOS2;
  CCmdStr CmdStr,CmdSubStr;

  string strFileName,strMatchStr;

  strFileName=str;
  strMatchStr=strTemp;

  // ���ַ�����ת���ɴ�д�������Ƚ�
  ToUpper(strFileName);
  ToUpper(strMatchStr);

  CmdStr.SplitToCmd(strMatchStr,",");

  for (ii=0;ii<CmdStr.CmdCount();ii++)
  {
    // ���Ϊ�գ���һ��Ҫ����������ͻᱻ����
    if (CmdStr.m_vCmdStr[ii].empty() == true) continue;

    iPOS1=iPOS2=0;
    CmdSubStr.SplitToCmd(CmdStr.m_vCmdStr[ii],"*");

    for (jj=0;jj<CmdSubStr.CmdCount();jj++)
    {
      // ������ļ������ײ�
      if (jj == 0)
      {
        if (strncmp(strFileName.c_str(),CmdSubStr.m_vCmdStr[jj].c_str(),CmdSubStr.m_vCmdStr[jj].size()) != 0) break;
      }

      // ������ļ�����β��
      if (jj == CmdSubStr.CmdCount()-1)
      {
        if (strcmp(strFileName.c_str()+strFileName.size()-CmdSubStr.m_vCmdStr[jj].size(),CmdSubStr.m_vCmdStr[jj].c_str()) != 0) break;
      }

      iPOS2=strFileName.find(CmdSubStr.m_vCmdStr[jj],iPOS1);

      if (iPOS2 < 0) break;

      iPOS1=iPOS2+CmdSubStr.m_vCmdStr[jj].size();
    }

    if (jj==CmdSubStr.CmdCount()) return true;
  }

  return false;
}

// �������ʽ���ж�һ���ַ����Ƿ�ƥ����һ���ַ�����
// ����MatchFileName������Ϊ�˼���֮ǰ�İ汾��
bool MatchFileName(const string in_FileName,const string in_MatchStr)
{
  return MatchStr(in_FileName,in_MatchStr);
}

// ͳ���ַ�����������ȫ�ǵĺ��ֺ�ȫ�ǵı�������һ���֣���ǵĺ��ֺͰ�ǵı�����Ҳ��һ���֡�
// str����ͳ�Ƶ��ַ�����
// ����ֵ���ַ���str��������
int Words(const char *str)
{
  int  wlen=0;
  bool biswide=0;
  int  ilen=strlen(str);

  for (int ii=0;ii<ilen;ii++)
  {
    if ( (unsigned int )str[ii] < 128)
    {
      wlen = wlen + 1;
    }
    else
    {
      if (biswide==true)
      {
        wlen = wlen + 1;
        biswide=false;
      }
      else
      {
        biswide=true;
      }
    }
  }

  return wlen;
}

CFile::CFile()   // ��Ĺ��캯��
{
  m_fp=0;
  m_bEnBuffer=true;
  memset(m_filename,0,sizeof(m_filename));
  memset(m_filenametmp,0,sizeof(m_filenametmp));
}

// �ر��ļ�ָ��
void CFile::Close() 
{
  if (m_fp==0) return;

  fclose(m_fp);  // �ر��ļ�ָ��

  m_fp=0;
  memset(m_filename,0,sizeof(m_filename));

  // ���������ʱ�ļ�����ɾ������
  if (strlen(m_filenametmp)!=0) remove(m_filenametmp);

  memset(m_filenametmp,0,sizeof(m_filenametmp));
}

// �ж��ļ��Ƿ��Ѵ�
bool CFile::IsOpened()
{
  if (m_fp==0) return false;

  return true;
}

// �ر��ļ�ָ�룬��ɾ���ļ�
bool CFile::CloseAndRemove()
{
  if (m_fp==0) return true;

  fclose(m_fp);  // �ر��ļ�ָ��

  m_fp=0;

  if (remove(m_filename) != 0) { memset(m_filename,0,sizeof(m_filename)); return false; }

  memset(m_filename,0,sizeof(m_filename));
  memset(m_filenametmp,0,sizeof(m_filenametmp));

  return true;
}

CFile::~CFile()   // �����������
{
  Close();
}

// ���ļ���������FOPEN��ͬ���򿪳ɹ�true��ʧ�ܷ���false
bool CFile::Open(const char *filename,const char *openmode,bool bEnBuffer)
{
  Close();

  if ( (m_fp=FOPEN(filename,openmode)) == 0 ) return false;

  memset(m_filename,0,sizeof(m_filename));

  strncpy(m_filename,filename,300);

  m_bEnBuffer=bEnBuffer;

  return true;
}

// רΪ���������ļ���������fopen��ͬ���򿪳ɹ�true��ʧ�ܷ���false
bool CFile::OpenForRename(const char *filename,const char *openmode,bool bEnBuffer)
{
  Close();

  memset(m_filename,0,sizeof(m_filename));
  strncpy(m_filename,filename,300);
  
  memset(m_filenametmp,0,sizeof(m_filenametmp));
  SNPRINTF(m_filenametmp,sizeof(m_filenametmp),300,"%s.tmp",m_filename);

  if ( (m_fp=FOPEN(m_filenametmp,openmode)) == 0 ) return false;

  m_bEnBuffer=bEnBuffer;

  return true;
}

// �ر��ļ�������
bool CFile::CloseAndRename()
{
  if (m_fp==0) return false;

  fclose(m_fp);  // �ر��ļ�ָ��

  m_fp=0;

  if (rename(m_filenametmp,m_filename) != 0)
  {
    remove(m_filenametmp);
    memset(m_filename,0,sizeof(m_filename));
    memset(m_filenametmp,0,sizeof(m_filenametmp));
    return false;
  }

  memset(m_filename,0,sizeof(m_filename));
  memset(m_filenametmp,0,sizeof(m_filenametmp));

  return true;
}

// ����fprintf���ļ�д������
void CFile::Fprintf(const char *fmt,...)
{
  if ( m_fp == 0 ) return;

  va_list arg;
  va_start( arg, fmt );
  vfprintf( m_fp, fmt, arg );
  va_end( arg );

  if ( m_bEnBuffer == false ) fflush(m_fp);
}

// ����fgets���ļ��ж�ȡһ�У�bDelCRT=trueɾ�����з���false��ɾ����ȱʡΪfalse
bool CFile::Fgets(char *buffer,const int readsize,bool bdelcrt)
{
  if ( m_fp == 0 ) return false;

  memset(buffer,0,readsize+1);  // �����߱��뱣֤buffer�Ŀռ��㹻������������ڴ������

  if (fgets(buffer,readsize,m_fp) == 0) return false;

  if (bdelcrt==true)
  {
    DeleteRChar(buffer,'\n'); DeleteRChar(buffer,'\r');  // ����ļ���windows��ʽ����Ҫɾ��'\r'��
  }

  return true;
}

// ���ļ��ļ��ж�ȡһ��
// strEndStr��һ�����ݵĽ�����־�����Ϊ�գ����Ի��з�"\n"Ϊ������־��
bool CFile::FFGETS(char *buffer,const int readsize,const char *endbz)
{
  if ( m_fp == 0 ) return false;

  return FGETS(m_fp,buffer,readsize,endbz);
}

// ����fread���ļ��ж�ȡ���ݡ�
size_t CFile::Fread(void *ptr, size_t size)
{
  if ( m_fp == 0 ) return -1;

  return fread(ptr,1,size,m_fp);
}

// ����fwrite���ļ���д����
size_t CFile::Fwrite(const void *ptr, size_t size )
{
  if ( m_fp == 0 ) return -1;

  size_t tt=fwrite(ptr,1,size,m_fp);

  if ( m_bEnBuffer == false ) fflush(m_fp);

  return tt;
}


// ���ı��ļ��ж�ȡһ�С�
// fp���Ѵ򿪵��ļ�ָ�롣
// buffer�����ڴ�Ŷ�ȡ�����ݡ�
// readsize�����δ����ȡ���ֽ���������Ѿ���ȡ���˽�����־���������ء�
// endbz�������ݽ����ı�־��ȱʡΪ�գ���ʾ��������"\n"Ϊ������־��
// ����ֵ��true-�ɹ���false-ʧ�ܣ�һ������£�ʧ�ܿ�����Ϊ���ļ��ѽ�����
bool FGETS(const FILE *fp,char *buffer,const int readsize,const char *endbz)
{
  if ( fp == 0 ) return false;

  memset(buffer,0,readsize+1);   // �����߱��뱣֤buffer�Ŀռ��㹻������������ڴ������

  char strline[readsize+1];

  while (true)
  {
    memset(strline,0,sizeof(strline));

    if (fgets(strline,readsize,(FILE *)fp) == 0) break;

    // ��ֹbuffer���
    if ( (strlen(buffer)+strlen(strline)) >= (unsigned int)readsize ) break;

    strcat(buffer,strline);

    if (endbz == 0) return true;
    else if (strstr(strline,endbz)!= 0) return true;
  }

  return false;
}


CCmdStr::CCmdStr()
{
  m_vCmdStr.clear();
}

// ���ַ�����ֵ�m_vCmdStr�����С�
// buffer������ֵ��ַ�����
// sepstr��buffer�ַ������ֶ����ݵķָ�����ע�⣬�ָ������ַ�������","��" "��"|"��"~!~"��
// bdelspace���Ƿ�ɾ����ֺ���ֶ�����ǰ��Ŀո�true-ɾ����false-��ɾ����ȱʡɾ����
void CCmdStr::SplitToCmd(const string buffer,const char *sepstr,const bool bdelspace)
{
  // ������еľ�����
  m_vCmdStr.clear();

  int iPOS=0;
  string srcstr,substr;

  srcstr=buffer;

  char str[2048];

  while ( (iPOS=srcstr.find(sepstr)) >= 0)
  {
    substr=srcstr.substr(0,iPOS);

    if (bdelspace == true)
    {
      memset(str,0,sizeof(str));

      strncpy(str,substr.c_str(),2000);

      DeleteLRChar(str,' ');

      substr=str;
    }

    m_vCmdStr.push_back(substr);

    iPOS=iPOS+strlen(sepstr);

    srcstr=srcstr.substr(iPOS,srcstr.size()-iPOS);

  }

  substr=srcstr;

  if (bdelspace == true)
  {
    memset(str,0,sizeof(str));

    strncpy(str,substr.c_str(),2000);

    DeleteLRChar(str,' ');

    substr=str;
  }

  m_vCmdStr.push_back(substr);

  return;
}

int CCmdStr::CmdCount()
{
  return m_vCmdStr.size();
}

bool CCmdStr::GetValue(const int inum,char *value,const int ilen)
{
  if ( (inum>=(int)m_vCmdStr.size()) || (value==0) ) return false;

  if (ilen>0) memset(value,0,ilen+1);   // �����߱��뱣֤value�Ŀռ��㹻������������ڴ������

  if ( (m_vCmdStr[inum].length()<=(unsigned int)ilen) || (ilen==0) )
  {
    strcpy(value,m_vCmdStr[inum].c_str());
  }
  else
  {
    strncpy(value,m_vCmdStr[inum].c_str(),ilen); value[ilen]=0;
  }

  return true;
}

bool CCmdStr::GetValue(const int inum,int *value)
{
  if ( (inum>=(int)m_vCmdStr.size()) || (value==0) ) return false;

  (*value) = 0;

  if (inum >= (int)m_vCmdStr.size()) return false;

  (*value) = atoi(m_vCmdStr[inum].c_str());

  return true;
}

bool CCmdStr::GetValue(const int inum,unsigned int *value)
{
  if ( (inum>=(int)m_vCmdStr.size()) || (value==0) ) return false;

  (*value) = 0;

  if (inum >= (int)m_vCmdStr.size()) return false;

  (*value) = atoi(m_vCmdStr[inum].c_str());

  return true;
}


bool CCmdStr::GetValue(const int inum,long *value)
{
  if ( (inum>=(int)m_vCmdStr.size()) || (value==0) ) return false;

  (*value) = 0;

  if (inum >= (int)m_vCmdStr.size()) return false;

  (*value) = atol(m_vCmdStr[inum].c_str());

  return true;
}

bool CCmdStr::GetValue(const int inum,unsigned long *value)
{
  if ( (inum>=(int)m_vCmdStr.size()) || (value==0) ) return false;

  (*value) = 0;

  if (inum >= (int)m_vCmdStr.size()) return false;

  (*value) = atol(m_vCmdStr[inum].c_str());

  return true;
}

bool CCmdStr::GetValue(const int inum,double *value)
{
  if ( (inum>=(int)m_vCmdStr.size()) || (value==0) ) return false;

  (*value) = 0;

  if (inum >= (int)m_vCmdStr.size()) return false;

  (*value) = (double)atof(m_vCmdStr[inum].c_str());

  return true;
}

bool CCmdStr::GetValue(const int inum,bool *value)
{
  if ( (inum>=(int)m_vCmdStr.size()) || (value==0) ) return false;

  (*value) = 0;

  if (inum >= (int)m_vCmdStr.size()) return false;

  char strTemp[11];
  memset(strTemp,0,sizeof(strTemp));
  strncpy(strTemp,m_vCmdStr[inum].c_str(),10);

  ToUpper(strTemp);  // ת��Ϊ��д���жϡ�
  if (strcmp(strTemp,"TRUE")==0) (*value)=true; 

  return true;
}

CCmdStr::~CCmdStr()
{
  m_vCmdStr.clear();
}

bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,char *value,const int ilen)
{
  if (value==0) return false;

  if (ilen>0) memset(value,0,ilen+1);   // �����߱��뱣֤value�Ŀռ��㹻������������ڴ������

  char *start=0,*end=0;
  char m_SFieldName[51],m_EFieldName[51];

  int m_NameLen = strlen(fieldname);
  memset(m_SFieldName,0,sizeof(m_SFieldName));
  memset(m_EFieldName,0,sizeof(m_EFieldName));

  snprintf(m_SFieldName,50,"<%s>",fieldname);
  snprintf(m_EFieldName,50,"</%s>",fieldname);

  start=0; end=0;

  start = (char *)strstr(xmlbuffer,m_SFieldName);

  if (start != 0)
  {
    end   = (char *)strstr(start,m_EFieldName);
  }

  if ((start==0) || (end == 0))
  {
    return false;
  }

  int   m_ValueLen = end - start - m_NameLen - 2 + 1 ;

  if ( ((m_ValueLen-1) <= ilen) || (ilen == 0) )
  {
    strncpy(value,start+m_NameLen+2,m_ValueLen-1); value[m_ValueLen-1]=0;
  }
  else
  {
    strncpy(value,start+m_NameLen+2,ilen); value[ilen]=0;
  }

  DeleteLRChar(value,' ');

  return true;
}

bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,bool *value)
{
  if (value==0) return false;

  (*value) = false;

  char strTemp[51];

  memset(strTemp,0,sizeof(strTemp));

  if (GetXMLBuffer(xmlbuffer,fieldname,strTemp,10) == true)
  {
    ToUpper(strTemp);  // ת��Ϊ��д���жϡ�
    if (strcmp(strTemp,"TRUE")==0) { (*value)=true; return true; }
  }

  return false;
}

bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,int *value)
{
  if (value==0) return false;

  (*value) = 0;

  char strTemp[51];

  memset(strTemp,0,sizeof(strTemp));

  if (GetXMLBuffer(xmlbuffer,fieldname,strTemp,50) == true)
  {
    (*value) = atoi(strTemp); return true;
  }

  return false;
}

bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,unsigned int *value)
{
  if (value==0) return false;

  (*value) = 0;

  char strTemp[51];

  memset(strTemp,0,sizeof(strTemp));

  if (GetXMLBuffer(xmlbuffer,fieldname,strTemp,50) == true)
  {
    (*value) = (unsigned int)atoi(strTemp); return true;
  }

  return false;
}

bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,long *value)
{
  if (value==0) return false;

  (*value) = 0;

  char strTemp[51];

  memset(strTemp,0,sizeof(strTemp));

  if (GetXMLBuffer(xmlbuffer,fieldname,strTemp,50) == true)
  {
    (*value) = atol(strTemp); return true;
  }

  return false;
}

bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,unsigned long *value)
{
  if (value==0) return false;

  (*value) = 0;

  char strTemp[51];

  memset(strTemp,0,sizeof(strTemp));

  if (GetXMLBuffer(xmlbuffer,fieldname,strTemp,50) == true)
  {
    (*value) = (unsigned long)atol(strTemp); return true;
  }

  return false;
}

bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,double *value)
{
  if (value==0) return false;

  (*value) = 0;

  char strTemp[51];

  memset(strTemp,0,sizeof(strTemp));

  if (GetXMLBuffer(xmlbuffer,fieldname,strTemp,50) == true)
  {
    (*value) = atof(strTemp); return true;
  }

  return false;
}

// ��������ʾ��ʱ��ת��Ϊ�ַ�����ʾ��ʱ�䡣
// ltime��������ʾ��ʱ�䡣
// stime���ַ�����ʾ��ʱ�䡣
// fmt������ַ���ʱ��stime�ĸ�ʽ����LocalTime������fmt������ͬ�����fmt�ĸ�ʽ����ȷ��stime��Ϊ�ա�
void timetostr(const time_t ltime,char *stime,const char *fmt)
{
  if (stime==0) return;

  strcpy(stime,"");

  struct tm sttm = *localtime ( &ltime ); 

  sttm.tm_year=sttm.tm_year+1900;
  sttm.tm_mon++;

  if (fmt==0)
  {
    snprintf(stime,20,"%04u-%02u-%02u %02u:%02u:%02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour,
                    sttm.tm_min,sttm.tm_sec);
    return;
  }

  if (strcmp(fmt,"yyyy-mm-dd hh24:mi:ss") == 0)
  {
    snprintf(stime,20,"%04u-%02u-%02u %02u:%02u:%02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour,
                    sttm.tm_min,sttm.tm_sec);
    return;
  }

  if (strcmp(fmt,"yyyy-mm-dd hh24:mi") == 0)
  {
    snprintf(stime,17,"%04u-%02u-%02u %02u:%02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour,
                    sttm.tm_min);
    return;
  }

  if (strcmp(fmt,"yyyy-mm-dd hh24") == 0)
  {
    snprintf(stime,14,"%04u-%02u-%02u %02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour);
    return;
  }

  if (strcmp(fmt,"yyyy-mm-dd") == 0)
  {
    snprintf(stime,11,"%04u-%02u-%02u",sttm.tm_year,sttm.tm_mon,sttm.tm_mday); 
    return;
  }

  if (strcmp(fmt,"yyyy-mm") == 0)
  {
    snprintf(stime,8,"%04u-%02u",sttm.tm_year,sttm.tm_mon); 
    return;
  }

  if (strcmp(fmt,"yyyymmddhh24miss") == 0)
  {
    snprintf(stime,15,"%04u%02u%02u%02u%02u%02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour,
                    sttm.tm_min,sttm.tm_sec);
    return;
  }

  if (strcmp(fmt,"yyyymmddhh24mi") == 0)
  {
    snprintf(stime,13,"%04u%02u%02u%02u%02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour,
                    sttm.tm_min);
    return;
  }

  if (strcmp(fmt,"yyyymmddhh24") == 0)
  {
    snprintf(stime,11,"%04u%02u%02u%02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour);
    return;
  }

  if (strcmp(fmt,"yyyymmdd") == 0)
  {
    snprintf(stime,9,"%04u%02u%02u",sttm.tm_year,sttm.tm_mon,sttm.tm_mday); 
    return;
  }

  if (strcmp(fmt,"hh24miss") == 0)
  {
    snprintf(stime,7,"%02u%02u%02u",sttm.tm_hour,sttm.tm_min,sttm.tm_sec); 
    return;
  }

  if (strcmp(fmt,"hh24mi") == 0)
  {
    snprintf(stime,5,"%02u%02u",sttm.tm_hour,sttm.tm_min); 
    return;
  }

  if (strcmp(fmt,"hh24") == 0)
  {
    snprintf(stime,3,"%02u",sttm.tm_hour); 
    return;
  }

  if (strcmp(fmt,"mi") == 0)
  {
    snprintf(stime,3,"%02u",sttm.tm_min); 
    return;
  }
}


/*
  ȡ����ϵͳ��ʱ�䣬����������ʾ��ʱ��ת��Ϊ�ַ�����ʾ�ĸ�ʽ��
  stime�����ڴ�Ż�ȡ����ʱ���ַ�����
  timetvl��ʱ���ƫ��������λ���룬0��ȱʡֵ����ʾ��ǰʱ�䣬30��ʾ��ǰʱ��30��֮���ʱ��㣬-30��ʾ��ǰʱ��30��֮ǰ��ʱ��㡣
  fmt�����ʱ��ĸ�ʽ��ȱʡ��"yyyy-mm-dd hh24:mi:ss"��Ŀǰ֧�����¸�ʽ��
  "yyyy-mm-dd hh24:mi:ss"���˸�ʽ��ȱʡ��ʽ��
  "yyyymmddhh24miss"
  "yyyy-mm-dd"
  "yyyymmdd"
  "hh24:mi:ss"
  "hh24miss"
  "hh24:mi"
  "hh24mi"
  "hh24"
  "mi"
  ע�⣺
    1��Сʱ�ı�ʾ������hh24������hh����ô����Ŀ����Ϊ�˱��������ݿ��ʱ���ʾ����һ�£�
    2�������г��˳��õ�ʱ���ʽ���������������Ӧ�ÿ������������޸�Դ�������Ӹ���ĸ�ʽ֧�֣�
    3�����ú�����ʱ�����fmt��������ʽ��ƥ�䣬stime�����ݽ�Ϊ�ա�
*/
void LocalTime(char *stime,const char *fmt,const int timetvl)
{
  if (stime==0) return;

  time_t  timer;

  time( &timer ); timer=timer+timetvl;

  timetostr(timer,stime,fmt);
}


CLogFile::CLogFile(const long MaxLogSize)
{
  m_tracefp = 0;
  memset(m_filename,0,sizeof(m_filename));
  memset(m_openmode,0,sizeof(m_openmode));
  m_bBackup=true;
  m_bEnBuffer=false;
  m_MaxLogSize=MaxLogSize;
  if (m_MaxLogSize<10) m_MaxLogSize=10;
}

CLogFile::~CLogFile()
{
  Close();
}

void CLogFile::Close()
{
  if (m_tracefp != 0) { fclose(m_tracefp); m_tracefp=0; }

  memset(m_filename,0,sizeof(m_filename));
  memset(m_openmode,0,sizeof(m_openmode));
  m_bBackup=true;
  m_bEnBuffer=false;
}

// ����־�ļ���
// filename����־�ļ�����������þ���·��������ļ����е�Ŀ¼�����ڣ����ȴ���Ŀ¼��
// openmode����־�ļ��Ĵ򿪷�ʽ����fopen�⺯�����ļ��ķ�ʽ��ͬ��ȱʡֵ��"a+"��
// bBackup���Ƿ��Զ��л���true-�л���false-���л����ڶ���̵ķ�������У����������й���һ����־�ļ���bBackup����Ϊfalse��
// bEnBuffer���Ƿ������ļ�������ƣ�true-���ã�false-�����ã�������û���������ôд����־�ļ��е����ݲ�������д���ļ���ȱʡ�ǲ����á�
bool CLogFile::Open(const char *filename,const char *openmode,bool bBackup,bool bEnBuffer)
{
  // ����ļ�ָ���Ǵ򿪵�״̬���ȹر�����
  Close();

  strcpy(m_filename,filename);
  m_bEnBuffer=bEnBuffer;
  m_bBackup=bBackup;
  if (openmode==0) strcpy(m_openmode,"a+");
  else strcpy(m_openmode,openmode);

  if ((m_tracefp=FOPEN(m_filename,m_openmode)) == 0) return false;

  return true;
}

// �����־�ļ�����100M���Ͱѵ�ǰ����־�ļ����ݳ���ʷ��־�ļ����л��ɹ�����յ�ǰ��־�ļ������ݡ�
// ���ݺ���ļ�������־�ļ������������ʱ�䡣
// ע�⣬�ڶ���̵ĳ����У���־�ļ������л������ߵĳ����У���־�ļ������л���
bool CLogFile::BackupLogFile()
{
  if (m_tracefp == 0) return false;

  // ������
  if (m_bBackup == false) return true;

  fseek(m_tracefp,0L,2);

  if (ftell(m_tracefp) > m_MaxLogSize*1024*1024)
  {
    fclose(m_tracefp); m_tracefp=0;

    char strLocalTime[21];
    memset(strLocalTime,0,sizeof(strLocalTime));
    LocalTime(strLocalTime,"yyyymmddhh24miss");

    char bak_filename[301];
    memset(bak_filename,0,sizeof(bak_filename));
    snprintf(bak_filename,300,"%s.%s",m_filename,strLocalTime);
    rename(m_filename,bak_filename);

    if ((m_tracefp=FOPEN(m_filename,m_openmode)) == 0) return false;
  }

  return true;
}

// ������д����־�ļ���fmt�ǿɱ������ʹ�÷�����printf�⺯����ͬ��
// Write������д�뵱ǰ��ʱ�䣬WriteEx������дʱ�䡣
bool CLogFile::Write(const char *fmt,...)
{
  if (m_tracefp == 0) return false;

  if (BackupLogFile() == false) return false;

  char strtime[20]; LocalTime(strtime);

  va_list ap;
  va_start(ap,fmt);
  fprintf(m_tracefp,"%s ",strtime);
  vfprintf(m_tracefp,fmt,ap);
  va_end(ap);

  if (m_bEnBuffer==false) fflush(m_tracefp);

  return true;
}

// ������д����־�ļ���fmt�ǿɱ������ʹ�÷�����printf�⺯����ͬ��
// Write������д�뵱ǰ��ʱ�䣬WriteEx������дʱ�䡣
bool CLogFile::WriteEx(const char *fmt,...)
{
  if (m_tracefp == 0) return false;

  va_list ap;
  va_start(ap,fmt);
  vfprintf(m_tracefp,fmt,ap);
  va_end(ap);

  if (m_bEnBuffer==false) fflush(m_tracefp);

  return true;
}

CIniFile::CIniFile()
{
  
}

bool CIniFile::LoadFile(const char *filename)
{
  m_xmlbuffer.clear();

  CFile File;

  if ( File.Open(filename,"r") == false) return false;

  char strLine[501];

  while (true)
  {
    memset(strLine,0,sizeof(strLine));

    if (File.FFGETS(strLine,500) == false) break;

    m_xmlbuffer=m_xmlbuffer+strLine;
  }

  if (m_xmlbuffer.length() < 10) return false;

  return true;
}

bool CIniFile::GetValue(const char *fieldname,bool   *value)
{
  return GetXMLBuffer(m_xmlbuffer.c_str(),fieldname,value);
}

bool CIniFile::GetValue(const char *fieldname,char *value,int ilen)
{
  return GetXMLBuffer(m_xmlbuffer.c_str(),fieldname,value,ilen);
}

bool CIniFile::GetValue(const char *fieldname,int *value)
{
  return GetXMLBuffer(m_xmlbuffer.c_str(),fieldname,value);
}

bool CIniFile::GetValue(const char *fieldname,unsigned int *value)
{
  return GetXMLBuffer(m_xmlbuffer.c_str(),fieldname,value);
}

bool CIniFile::GetValue(const char *fieldname,long *value)
{
  return GetXMLBuffer(m_xmlbuffer.c_str(),fieldname,value);
}

bool CIniFile::GetValue(const char *fieldname,unsigned long *value)
{
  return GetXMLBuffer(m_xmlbuffer.c_str(),fieldname,value);
}

bool CIniFile::GetValue(const char *fieldname,double *value)
{
  return GetXMLBuffer(m_xmlbuffer.c_str(),fieldname,value);
}

// �ر�ȫ�����źź��������
void CloseIOAndSignal()
{
  int ii=0;

  for (ii=0;ii<100;ii++)
  {
    signal(ii,SIG_IGN); close(ii);
  }
}

// ���ݾ���·�����ļ�����Ŀ¼���𼶵Ĵ���Ŀ¼��
// pathorfilename������·�����ļ�����Ŀ¼����
// bisfilename��˵��pathorfilename�����ͣ�true-pathorfilename���ļ�����������Ŀ¼����ȱʡֵΪtrue��
// ����ֵ��true-�����ɹ���false-����ʧ�ܣ��������ʧ�ܣ�ԭ���д�������������1��Ȩ�޲��㣻 2��pathorfilename�������ǺϷ����ļ�����Ŀ¼����3�����̿ռ䲻�㡣
bool MKDIR(const char *filename,bool bisfilename)
{
  // ���Ŀ¼�Ƿ���ڣ���������ڣ��𼶴�����Ŀ¼
  char strPathName[301];

  int ilen=strlen(filename);

  for (int ii=1; ii<ilen;ii++)
  {
    if (filename[ii] != '/') continue;

    memset(strPathName,0,sizeof(strPathName));
    strncpy(strPathName,filename,ii);

    if (access(strPathName,F_OK) == 0) continue;

#ifdef _WIN32
    if (mkdir(strPathName) != 0) return false;
#else
    if (mkdir(strPathName,0755) != 0) return false;
#endif
  }

  if (bisfilename==false)
  {
    if (access(filename,F_OK) != 0)
    {
#ifdef _WIN32
      if (mkdir(filename) != 0) return false;
#else
      if (mkdir(filename,0755) != 0) return false;
#endif
    }
  }

  return true;
}

// ���ļ���
// FOPEN��������fopen�⺯�����ļ�������ļ����а�����Ŀ¼�����ڣ��ʹ���Ŀ¼��
// FOPEN�����Ĳ����ͷ���ֵ��fopen������ȫ��ͬ��
// ��Ӧ�ÿ����У���FOPEN��������fopen�⺯����
FILE *FOPEN(const char *filename,const char *mode)
{
  if (MKDIR(filename) == false) return 0;

  return fopen(filename,mode);
}

// ��ȡ�ļ��Ĵ�С��
// filename������ȡ���ļ�����������þ���·�����ļ�����
// ����ֵ������ļ������ڻ�û�з���Ȩ�ޣ�����-1���ɹ������ļ��Ĵ�С����λ���ֽڡ�
int FileSize(const char *filename)
{
  struct stat st_filestat;

  if (stat(filename,&st_filestat) < 0) return -1;

  return st_filestat.st_size;
}

// �����ļ����޸�ʱ�����ԡ�
// filename�������õ��ļ�����������þ���·�����ļ�����
// stime���ַ�����ʾ��ʱ�䣬��ʽ���ޣ���һ��Ҫ����yyyymmddhh24miss��һ���������١�
// ����ֵ��true-�ɹ���false-ʧ�ܣ�ʧ�ܵ�ԭ�򱣴���errno�С�
bool UTime(const char *filename,const char *mtime)
{
  struct utimbuf stutimbuf;

  stutimbuf.actime=stutimbuf.modtime=strtotime(mtime);

  if (utime(filename,&stutimbuf)!=0) return false;

  return true;
}

// ���ַ�����ʾ��ʱ��ת��Ϊ������ʾ��ʱ�䡣
// stime���ַ�����ʾ��ʱ�䣬��ʽ���ޣ���һ��Ҫ����yyyymmddhh24miss��һ���������١�
// ����ֵ��������ʾ��ʱ�䣬���stime�ĸ�ʽ����ȷ������-1��
time_t strtotime(const char *stime)
{
  char strtime[21],yyyy[5],mm[3],dd[3],hh[3],mi[3],ss[3];
  memset(strtime,0,sizeof(strtime));
  memset(yyyy,0,sizeof(yyyy));
  memset(mm,0,sizeof(mm));
  memset(dd,0,sizeof(dd));
  memset(hh,0,sizeof(hh));
  memset(mi,0,sizeof(mi));
  memset(ss,0,sizeof(ss));

  PickNumber(stime,strtime,false,false);

  if (strlen(strtime) != 14) return -1;

  strncpy(yyyy,strtime,4);
  strncpy(mm,strtime+4,2);
  strncpy(dd,strtime+6,2);
  strncpy(hh,strtime+8,2);
  strncpy(mi,strtime+10,2);
  strncpy(ss,strtime+12,2);

  struct tm time_str;

  time_str.tm_year = atoi(yyyy) - 1900;
  time_str.tm_mon = atoi(mm) - 1;
  time_str.tm_mday = atoi(dd);
  time_str.tm_hour = atoi(hh);
  time_str.tm_min = atoi(mi);
  time_str.tm_sec = atoi(ss);
  time_str.tm_isdst = 0;

  return mktime(&time_str);
}

// ���ַ�����ʾ��ʱ�����һ��ƫ�Ƶ�������õ�һ���µ��ַ�����ʾ��ʱ�䡣
// in_stime��������ַ�����ʽ��ʱ�䡣
// out_stime��������ַ�����ʽ��ʱ�䡣
// timetvl����Ҫƫ�Ƶ���������������ƫ�ƣ�������ǰƫ�ơ�
// fmt������ַ���ʱ��out_stime�ĸ�ʽ����LocalTime������fmt������ͬ��
// ע�⣺in_stime��out_stime����������ͬһ�������ĵ�ַ���������ʧ�ܣ�out_stime�����ݻ���ա�
// ����ֵ��true-�ɹ���false-ʧ�ܣ��������ʧ�ܣ�������Ϊ��in_stime�ĸ�ʽ����ȷ��
bool AddTime(const char *in_stime,char *out_stime,const int timetvl,const char *fmt)
{
  if ( (in_stime==0) || (out_stime==0) ) return false;

  time_t  timer;
  if ( (timer=strtotime(in_stime)) == -1) { strcpy(out_stime,""); return false; }

  timer=timer+timetvl;

  strcpy(out_stime,"");

  timetostr(timer,out_stime,fmt);

  return true;
}

// ��ȡ�ļ���ʱ�䡣
// filename������ȡ���ļ�����������þ���·�����ļ�����
// mtime�����ڴ���ļ���ʱ�䣬��stat�ṹ���st_mtime��
// fmt������ʱ��������ʽ����LocalTime������ͬ����ȱʡ��"yyyymmddhh24miss"��
// ����ֵ������ļ������ڻ�û�з���Ȩ�ޣ�����false���ɹ�����true��
bool FileMTime(const char *filename,char *mtime,const char *fmt)
{
  // �ж��ļ��Ƿ���ڡ�
  struct stat st_filestat;

  if (stat(filename,&st_filestat) < 0) return false;

  char strfmt[25];
  memset(strfmt,0,sizeof(strfmt));
  if (fmt==0) strcpy(strfmt,"yyyymmddhh24miss");
  else strcpy(strfmt,fmt);

  timetostr(st_filestat.st_mtime,mtime,strfmt);

  return true;
}


CDir::CDir()
{
  m_pos=0;

  memset(m_DateFMT,0,sizeof(m_DateFMT));
  strcpy(m_DateFMT,"yyyy-mm-dd hh24:mi:ss");

  m_vFileName.clear();

  initdata();
}

void CDir::initdata()
{
  memset(m_DirName,0,sizeof(m_DirName));
  memset(m_FileName,0,sizeof(m_FileName));
  memset(m_FullFileName,0,sizeof(m_FullFileName));
  m_FileSize=0;
  memset(m_CreateTime,0,sizeof(m_CreateTime));
  memset(m_ModifyTime,0,sizeof(m_ModifyTime));
  memset(m_AccessTime,0,sizeof(m_AccessTime));
}

// �����ļ�ʱ��ĸ�ʽ��֧��"yyyy-mm-dd hh24:mi:ss"��"yyyymmddhh24miss"���֣�ȱʡ��ǰ�ߡ�
void CDir::SetDateFMT(const char *in_DateFMT)
{
  memset(m_DateFMT,0,sizeof(m_DateFMT));
  strcpy(m_DateFMT,in_DateFMT);
}

// ��Ŀ¼����ȡĿ¼�е��ļ��б���Ϣ�������m_vFileName�����С�
// in_DirName�����򿪵�Ŀ¼����
// in_MatchStr������ȡ�ļ�����ƥ����򣬲�ƥ����ļ������ԡ�
// in_MaxCount����ȡ�ļ������������ȱʡֵΪ10000����
// bAndChild���Ƿ�򿪸�����Ŀ¼��ȱʡֵΪfalse-������Ŀ¼��
// bSort���Ƿ�Ի�ȡ�����ļ��б�����m_vFileName�����е����ݣ���������ȱʡֵΪfalse-������
// ����ֵ�����in_DirName����ָ����Ŀ¼�����ڣ�OpenDir�����ᴴ����Ŀ¼���������ʧ�ܣ�����false�����У������ǰ�û���in_DirNameĿ¼�µ���Ŀ¼û�ж�ȡȨ��Ҳ�᷵��false��������������¶��᷵��true��
bool CDir::OpenDir(const char *in_DirName,const char *in_MatchStr,const unsigned int in_MaxCount,const bool bAndChild,bool bSort)
{
  m_pos=0;
  m_vFileName.clear();

  // ���Ŀ¼�����ڣ��ʹ�����Ŀ¼
  if (MKDIR(in_DirName,false) == false) return false;

  bool bRet=_OpenDir(in_DirName,in_MatchStr,in_MaxCount,bAndChild);

  if (bSort==true)
  {
    sort(m_vFileName.begin(), m_vFileName.end());
  }

  return bRet;
}

// ����һ���ݹ麯��������OpenDir()�ĵ��ã���CDir����ⲿ����Ҫ��������
bool CDir::_OpenDir(const char *in_DirName,const char *in_MatchStr,const unsigned int in_MaxCount,const bool bAndChild)
{
  DIR *dir;

  if ( (dir=opendir(in_DirName)) == 0 ) return false;

  char strTempFileName[1024];

  struct dirent *st_fileinfo;
  struct stat st_filestat;

  while ((st_fileinfo=readdir(dir)) != 0)
  {
    // ��"."��ͷ���ļ�������
    if (st_fileinfo->d_name[0]=='.') continue;
        
    memset(strTempFileName,0,sizeof(strTempFileName));

    snprintf(strTempFileName,300,"%s//%s",in_DirName,st_fileinfo->d_name);

    UpdateStr(strTempFileName,"//","/");

    stat(strTempFileName,&st_filestat);

    // �ж��Ƿ���Ŀ¼
    if (S_ISDIR(st_filestat.st_mode))
    {
      if (bAndChild == true)
      {
        if (_OpenDir(strTempFileName,in_MatchStr,in_MaxCount,bAndChild) == false) 
        {
          closedir(dir); return false;
        }
      }
    }
    else
    {
      if (MatchFileName(st_fileinfo->d_name,in_MatchStr) == false) continue;

      m_vFileName.push_back(strTempFileName);

      if ( m_vFileName.size()>=in_MaxCount ) break;
    }
  }

  closedir(dir);

  return true;
}

/*
st_gid 
  Numeric identifier of group that owns file (UNIX-specific) This field will always be zero on NT systems. A redirected file is classified as an NT file.
st_atime
  Time of last access of file.
st_ctime
  Time of creation of file.
st_dev
  Drive number of the disk containing the file (same as st_rdev).
st_ino
  Number of the information node (the inode) for the file (UNIX-specific). On UNIX file systems, the inode describes the file date and time stamps, permissions, and content. When files are hard-linked to one another, they share the same inode. The inode, and therefore st_ino, has no meaning in the FAT, HPFS, or NTFS file systems.
st_mode
  Bit mask for file-mode information. The _S_IFDIR bit is set if path specifies a directory; the _S_IFREG bit is set if path specifies an ordinary file or a device. User read/write bits are set according to the file��s permission mode; user execute bits are set according to the filename extension.
st_mtime
  Time of last modification of file.
st_nlink
  Always 1 on non-NTFS file systems.
st_rdev
  Drive number of the disk containing the file (same as st_dev).
st_size
  Size of the file in bytes; a 64-bit integer for _stati64 and _wstati64
st_uid
  Numeric identifier of user who owns file (UNIX-specific). This field will always be zero on NT systems. A redirected file is classified as an NT file.
*/

// ��m_vFileName�����л�ȡһ����¼���ļ�������ͬʱ�õ����ļ��Ĵ�С���޸�ʱ�����Ϣ��
// ����OpenDir����ʱ��m_vFileName��������գ�m_pos���㣬ÿ����һ��ReadDir����m_pos��1��
// ��m_posС��m_vFileName.size()������true�����򷵻�false��
bool CDir::ReadDir()
{
  initdata();

  int ivsize=m_vFileName.size();

  // ����Ѷ��꣬�������
  if (m_pos >= ivsize) 
  {
    m_pos=0; m_vFileName.clear(); return false;
  }

  int pos=0;

  pos=m_vFileName[m_pos].find_last_of("/");

  // Ŀ¼��
  memset(m_DirName,0,sizeof(m_DirName));
  strcpy(m_DirName,m_vFileName[m_pos].substr(0,pos).c_str());

  // �ļ���
  memset(m_FileName,0,sizeof(m_FileName));
  strcpy(m_FileName,m_vFileName[m_pos].substr(pos+1,m_vFileName[m_pos].size()-pos-1).c_str());

  // �ļ�ȫ��������·��
  snprintf(m_FullFileName,300,"%s",m_vFileName[m_pos].c_str());

  struct stat st_filestat;

  stat(m_FullFileName,&st_filestat);

  m_FileSize=st_filestat.st_size;

  struct tm nowtimer;

  if (strcmp(m_DateFMT,"yyyy-mm-dd hh24:mi:ss") == 0)
  {
    nowtimer = *localtime(&st_filestat.st_mtime); nowtimer.tm_mon++;
    snprintf(m_ModifyTime,20,"%04u-%02u-%02u %02u:%02u:%02u",\
             nowtimer.tm_year+1900,nowtimer.tm_mon,nowtimer.tm_mday,\
             nowtimer.tm_hour,nowtimer.tm_min,nowtimer.tm_sec);

    nowtimer = *localtime(&st_filestat.st_ctime); nowtimer.tm_mon++;
    snprintf(m_CreateTime,20,"%04u-%02u-%02u %02u:%02u:%02u",\
             nowtimer.tm_year+1900,nowtimer.tm_mon,nowtimer.tm_mday,\
             nowtimer.tm_hour,nowtimer.tm_min,nowtimer.tm_sec);

    nowtimer = *localtime(&st_filestat.st_atime); nowtimer.tm_mon++;
    snprintf(m_AccessTime,20,"%04u-%02u-%02u %02u:%02u:%02u",\
             nowtimer.tm_year+1900,nowtimer.tm_mon,nowtimer.tm_mday,\
             nowtimer.tm_hour,nowtimer.tm_min,nowtimer.tm_sec);
  }

  if (strcmp(m_DateFMT,"yyyymmddhh24miss") == 0)
  {
    nowtimer = *localtime(&st_filestat.st_mtime); nowtimer.tm_mon++;
    snprintf(m_ModifyTime,20,"%04u%02u%02u%02u%02u%02u",\
             nowtimer.tm_year+1900,nowtimer.tm_mon,nowtimer.tm_mday,\
             nowtimer.tm_hour,nowtimer.tm_min,nowtimer.tm_sec);

    nowtimer = *localtime(&st_filestat.st_ctime); nowtimer.tm_mon++;
    snprintf(m_CreateTime,20,"%04u%02u%02u%02u%02u%02u",\
             nowtimer.tm_year+1900,nowtimer.tm_mon,nowtimer.tm_mday,\
             nowtimer.tm_hour,nowtimer.tm_min,nowtimer.tm_sec);

    nowtimer = *localtime(&st_filestat.st_atime); nowtimer.tm_mon++;
    snprintf(m_AccessTime,20,"%04u%02u%02u%02u%02u%02u",\
             nowtimer.tm_year+1900,nowtimer.tm_mon,nowtimer.tm_mday,\
             nowtimer.tm_hour,nowtimer.tm_min,nowtimer.tm_sec);
  }

  m_pos++;

  return true;
}

CDir::~CDir()
{
  m_vFileName.clear();

  // m_vDirName.clear();
}

// ɾ��Ŀ¼�е��ļ�������Linuxϵͳ��rm���
// filename����ɾ�����ļ�����������þ���·�����ļ���������/tmp/root/data.xml��
// times��ִ��ɾ���ļ��Ĵ�����ȱʡ��1�����鲻Ҫ����3����ʵ��Ӧ�õľ��鿴�������ɾ���ļ���1�β��ɹ����ٳ���
// 2���ǿ��Եģ���������岻���ˡ����У����ִ��ɾ��ʧ�ܣ�usleep(100000)�������ԡ�
// ����ֵ��true-ɾ���ɹ���false-ɾ��ʧ�ܣ�ʧ�ܵ���Ҫԭ����Ȩ�޲��㡣
// ��Ӧ�ÿ����У�������REMOVE��������remove�⺯����
bool REMOVE(const char *filename,const int times)
{
  // ����ļ������ڣ�ֱ�ӷ���ʧ��
  if (access(filename,R_OK) != 0) return false;

  for (int ii=0;ii<times;ii++)
  {
    if (remove(filename) == 0) return true;

    usleep(100000);
  }

  return false;
}

// ���ļ�������������Linuxϵͳ��mv���
// srcfilename��ԭ�ļ�����������þ���·�����ļ�����
// destfilename��Ŀ���ļ�����������þ���·�����ļ�����
// times��ִ���������ļ��Ĵ�����ȱʡ��1�����鲻Ҫ����3����ʵ��Ӧ�õľ��鿴��������������ļ���1�β��ɹ����ٳ�
// ��2���ǿ��Եģ�����ξ����岻���ˡ����У����ִ��������ʧ�ܣ�usleep(100000)�������ԡ�
// ����ֵ��true-�������ɹ���false-������ʧ�ܣ�ʧ�ܵ���Ҫԭ����Ȩ�޲������̿ռ䲻�������ԭ�ļ���Ŀ���ļ���
// ��ͬһ�����̷�����������Ҳ����ʧ�ܡ�
// ע�⣬���������ļ�֮ǰ�����Զ�����destfilename�����е�Ŀ¼����
// ��Ӧ�ÿ����У�������RENAME��������rename�⺯����
bool RENAME(const char *srcfilename,const char *dstfilename,const int times)
{
  // ����ļ������ڣ�ֱ�ӷ���ʧ��
  if (access(srcfilename,R_OK) != 0) return false;

  if (MKDIR(dstfilename) == false) return false;

  for (int ii=0;ii<times;ii++)
  {
    if (rename(srcfilename,dstfilename) == 0) return true;

    usleep(100000);
  }

  return false;
}


CTcpClient::CTcpClient()
{
  m_sockfd=-1;
  memset(m_ip,0,sizeof(m_ip));
  m_port=0;
  m_btimeout=false;
}

bool CTcpClient::ConnectToServer(const char *ip,const int port)
{
  if (m_sockfd != -1) { close(m_sockfd); m_sockfd = -1; }

  strcpy(m_ip,ip);
  m_port=port;

  struct hostent* h;
  struct sockaddr_in servaddr;

  if ( (m_sockfd = socket(AF_INET,SOCK_STREAM,0) ) < 0) return false;

  if ( !(h = gethostbyname(m_ip)) )
  {
    close(m_sockfd);  m_sockfd = -1; return false;
  }

  memset(&servaddr,0,sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(m_port);  // ָ������˵�ͨѶ�˿�
  memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

  if (connect(m_sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0)
  {
    close(m_sockfd);  m_sockfd = -1; return false;
  }

  return true;
}

bool CTcpClient::Read(char *buffer,const int itimeout)
{
  if (m_sockfd == -1) return false;

  if (itimeout>0)
  {
    fd_set tmpfd;

    FD_ZERO(&tmpfd);
    FD_SET(m_sockfd,&tmpfd);

    struct timeval timeout;
    timeout.tv_sec = itimeout; timeout.tv_usec = 0;

    m_btimeout = false;

    int i;
    if ( (i = select(m_sockfd+1,&tmpfd,0,0,&timeout)) <= 0 )
    {
      if (i==0) m_btimeout = true;
      return false;
    }
  }

  m_buflen = 0;
  return (TcpRead(m_sockfd,buffer,&m_buflen));
}

bool CTcpClient::Write(const char *buffer,const int ibuflen)
{
  if (m_sockfd == -1) return false;

  fd_set tmpfd;

  FD_ZERO(&tmpfd);
  FD_SET(m_sockfd,&tmpfd);

  struct timeval timeout;
  timeout.tv_sec = 5; timeout.tv_usec = 0;
  
  m_btimeout = false;

  int i;
  if ( (i=select(m_sockfd+1,0,&tmpfd,0,&timeout)) <= 0 )
  {
    if (i==0) m_btimeout = true;
    return false;
  }

  int ilen=ibuflen;

  if (ibuflen==0) ilen=strlen(buffer);

  return(TcpWrite(m_sockfd,buffer,ilen));
}

void CTcpClient::Close()
{
  if (m_sockfd > 0) close(m_sockfd); 

  m_sockfd=-1;
  memset(m_ip,0,sizeof(m_ip));
  m_port=0;
  m_btimeout=false;
}

CTcpClient::~CTcpClient()
{
  Close();
}

CTcpServer::CTcpServer()
{
  m_listenfd=-1;
  m_connfd=-1;
  m_socklen=0;
  m_btimeout=false;
}

bool CTcpServer::InitServer(const unsigned int port)
{
  if (m_listenfd > 0) { close(m_listenfd); m_listenfd=-1; }

  m_listenfd = socket(AF_INET,SOCK_STREAM,0);

  // WINDOWSƽ̨����
  //char b_opt='1';
  //setsockopt(m_listenfd,SOL_SOCKET,SO_REUSEADDR,&b_opt,sizeof(b_opt));

  // Linux����
  int opt = 1; unsigned int len = sizeof(opt);
  #ifdef _WIN32
  char b_opt='1';
  setsockopt(m_listenfd,SOL_SOCKET,SO_REUSEADDR,&b_opt,sizeof(b_opt));
  #else
  setsockopt(m_listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,len);
  #endif

  memset(&m_servaddr,0,sizeof(m_servaddr));
  m_servaddr.sin_family = AF_INET;
  m_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  m_servaddr.sin_port = htons(port);
  if (bind(m_listenfd,(struct sockaddr *)&m_servaddr,sizeof(m_servaddr)) != 0 )
  {
    CloseListen(); return false;
  }

  if (listen(m_listenfd,5) != 0 )
  {
    CloseListen(); return false;
  }

  m_socklen = sizeof(struct sockaddr_in);

  return true;
}

bool CTcpServer::Accept()
{
  if (m_listenfd == -1) return false;

  if ((m_connfd=accept(m_listenfd,(struct sockaddr *)&m_clientaddr,(socklen_t*)&m_socklen)) < 0)
      return false;

  return true;
}

char *CTcpServer::GetIP()
{
  return(inet_ntoa(m_clientaddr.sin_addr));
}

bool CTcpServer::Read(char *buffer,const int itimeout)
{
  if (m_connfd == -1) return false;

  if (itimeout>0)
  {
    fd_set tmpfd;

    FD_ZERO(&tmpfd);
    FD_SET(m_connfd,&tmpfd);

    struct timeval timeout;
    timeout.tv_sec = itimeout; timeout.tv_usec = 0;

    m_btimeout = false;

    int i;
    if ( (i = select(m_connfd+1,&tmpfd,0,0,&timeout)) <= 0 )
    {
      if (i==0) m_btimeout = true;
      return false;
    }
  }

  m_buflen = 0;
  return(TcpRead(m_connfd,buffer,&m_buflen));
}

bool CTcpServer::Write(const char *buffer,const int ibuflen)
{
  if (m_connfd == -1) return false;

  fd_set tmpfd;

  FD_ZERO(&tmpfd);
  FD_SET(m_connfd,&tmpfd);

  struct timeval timeout;
  timeout.tv_sec = 5; timeout.tv_usec = 0;
  
  m_btimeout = false;

  int i;
  if ( (i=select(m_connfd+1,0,&tmpfd,0,&timeout)) <= 0 )
  {
    if (i==0) m_btimeout = true;
    return false;
  }

  int ilen = ibuflen;
  if (ilen==0) ilen=strlen(buffer);

  return(TcpWrite(m_connfd,buffer,ilen));
}

void CTcpServer::CloseListen()
{
  if (m_listenfd > 0)
  {
    close(m_listenfd); m_listenfd=-1;
  }
}

void CTcpServer::CloseClient()
{
  if (m_connfd > 0)
  {
    close(m_connfd); m_connfd=-1; 
  }
}

CTcpServer::~CTcpServer()
{
  CloseListen(); CloseClient();
}

bool TcpRead(const int sockfd,char *buffer,int *ibuflen,const int itimeout)
{
  if (sockfd == -1) return false;

  if (itimeout > 0)
  {
    fd_set tmpfd;

    FD_ZERO(&tmpfd);
    FD_SET(sockfd,&tmpfd);

    struct timeval timeout;
    timeout.tv_sec = itimeout; timeout.tv_usec = 0;

    int i;
    if ( (i = select(sockfd+1,&tmpfd,0,0,&timeout)) <= 0 ) return false;
  }

  (*ibuflen) = 0;

  if (Readn(sockfd,(char*)ibuflen,4) == false) return false;

  (*ibuflen)=ntohl(*ibuflen);  // �������ֽ���ת��Ϊ�����ֽ���

  if (Readn(sockfd,buffer,(*ibuflen)) == false) return false;

  return true;
}

bool TcpWrite(const int sockfd,const char *buffer,const int ibuflen)
{
  if (sockfd == -1) return false;

  fd_set tmpfd;

  FD_ZERO(&tmpfd);
  FD_SET(sockfd,&tmpfd);

  struct timeval timeout;
  timeout.tv_sec = 5; timeout.tv_usec = 0;

  if ( select(sockfd+1,0,&tmpfd,0,&timeout) <= 0 ) return false;
  
  int ilen=0;

  // �������Ϊ0���Ͳ����ַ����ĳ���
  if (ibuflen==0) ilen=strlen(buffer);
  else ilen=ibuflen;

  int ilenn=htonl(ilen);  // ת��Ϊ�����ֽ���

  char strTBuffer[ilen+4];
  memset(strTBuffer,0,sizeof(strTBuffer));
  memcpy(strTBuffer,&ilenn,4);
  memcpy(strTBuffer+4,buffer,ilen);
  
  if (Writen(sockfd,strTBuffer,ilen+4) == false) return false;

  return true;
}

bool Readn(const int sockfd,char *buffer,const size_t n)
{
  int nLeft,nread,idx;

  nLeft = n;
  idx = 0;

  while(nLeft > 0)
  {
    if ( (nread = recv(sockfd,buffer + idx,nLeft,0)) <= 0) return false;

    idx += nread;
    nLeft -= nread;
  }

  return true;
}

bool Writen(const int sockfd,const char *buffer,const size_t n)
{
  int nLeft,idx,nwritten;
  nLeft = n;  
  idx = 0;
  while(nLeft > 0 )
  {    
    if ( (nwritten = send(sockfd, buffer + idx,nLeft,0)) <= 0) return false;      
    
    nLeft -= nwritten;
    idx += nwritten;
  }

  return true;
}


// ���ļ�ͨ��sockfd���͸��Զ�
bool SendFile(int sockfd,struct st_fileinfo *stfileinfo,CLogFile *logfile)
{
  char strSendBuffer[301],strRecvBuffer[301];
  memset(strSendBuffer,0,sizeof(strSendBuffer));

  snprintf(strSendBuffer,300,"<filename>%s</filename><filesize>%d</filesize><mtime>%s</mtime>",stfileinfo->filename,stfileinfo->filesize,stfileinfo->mtime);

  if (TcpWrite(sockfd,strSendBuffer) == false)
  {
    if (logfile!=0) logfile->Write("SendFile TcpWrite() failed.\n"); 
    return false;
  }

  int  bytes=0;
  int  total_bytes=0;
  int  onread=0;
  char buffer[1000];

  FILE *fp=0;

  if ( (fp=FOPEN(stfileinfo->filename,"rb")) == 0 )
  {
    if (logfile!=0) logfile->Write("SendFile FOPEN(%s) failed.\n",stfileinfo->filename); 
    return false;
  }

  while (true)
  {
    memset(buffer,0,sizeof(buffer));

    if ((stfileinfo->filesize-total_bytes) > 1000) onread=1000;
    else onread=stfileinfo->filesize-total_bytes;

    bytes=fread(buffer,1,onread,fp);

    if (bytes > 0)
    {
      if (Writen(sockfd,buffer,bytes) == false)
      {
        if (logfile!=0) logfile->Write("SendFile Writen() failed.\n"); 
        fclose(fp); fp=0; return false;
      }
    }

    total_bytes = total_bytes + bytes;

    if ((int)total_bytes == stfileinfo->filesize) break;
  }

  fclose(fp);

  // ���նԶ˷��ص�ȷ�ϱ���
  int buflen=0;
  memset(strRecvBuffer,0,sizeof(strRecvBuffer));
  if (TcpRead(sockfd,strRecvBuffer,&buflen)==false)
  {
    if (logfile!=0) logfile->Write("SendFile TcpRead() failed.\n"); 
    return false;
  }

  if (strcmp(strRecvBuffer,"ok")!=0) return false;

  return true;
}

// ����ͨ��socdfd���͹������ļ�
bool RecvFile(int sockfd,struct st_fileinfo *stfileinfo,CLogFile *logfile)
{
  char strSendBuffer[301];

  char strfilenametmp[301]; memset(strfilenametmp,0,sizeof(strfilenametmp));
  sprintf(strfilenametmp,"%s.tmp",stfileinfo->filename);

  FILE *fp=0;

  if ( (fp=FOPEN(strfilenametmp,"wb")) ==0)     // FOPEN�ɴ���Ŀ¼
  {
    if (logfile!=0) logfile->Write("RecvFile FOPEN %s failed.\n",strfilenametmp); 
    return false;
  }

  int  total_bytes=0;
  int  onread=0;
  char buffer[1000];

  while (true)
  {
    memset(buffer,0,sizeof(buffer));

    if ((stfileinfo->filesize-total_bytes) > 1000) onread=1000;
    else onread=stfileinfo->filesize-total_bytes;

    if (Readn(sockfd,buffer,onread) == false)
    {
      if (logfile!=0) logfile->Write("RecvFile Readn() failed.\n"); 
      fclose(fp); fp=0; return false;
    }

    fwrite(buffer,1,onread,fp);

    total_bytes = total_bytes + onread;

    if ((int)total_bytes == stfileinfo->filesize) break;
  }

  fclose(fp);

  // �����ļ���ʱ��
  UTime(strfilenametmp,stfileinfo->mtime);

  memset(strSendBuffer,0,sizeof(strSendBuffer));
  if (RENAME(strfilenametmp,stfileinfo->filename)==true) strcpy(strSendBuffer,"ok");
  else strcpy(strSendBuffer,"failed");

  // ��Զ˷�����Ӧ����
  if (TcpWrite(sockfd,strSendBuffer)==false)
  {
    if (logfile!=0) logfile->Write("RecvFile TcpWrite() failed.\n"); 
    return false;
  }

  if (strcmp(strSendBuffer,"ok") != 0) return false;

  return true;
}

// �����ļ�������Linuxϵͳ��cp���
// srcfilename��ԭ�ļ�����������þ���·�����ļ�����
// destfilename��Ŀ���ļ�����������þ���·�����ļ�����
// ����ֵ��true-���Ƴɹ���false-����ʧ�ܣ�ʧ�ܵ���Ҫԭ����Ȩ�޲������̿ռ䲻����
// ע�⣺
// 1���ڸ������ļ�֮ǰ�����Զ�����destfilename�����е�Ŀ¼����
// 2�������ļ��Ĺ����У�������ʱ�ļ������ķ�����������ɺ��ٸ���Ϊdestfilename�������м�״̬���ļ�����ȡ��
// 3�����ƺ���ļ���ʱ����ԭ�ļ���ͬ����һ����Linuxϵͳcp���ͬ��
bool COPY(const char *srcfilename,const char *dstfilename)
{
  if (MKDIR(dstfilename) == false) return false;

  char strdstfilenametmp[301];
  memset(strdstfilenametmp,0,sizeof(strdstfilenametmp));
  snprintf(strdstfilenametmp,300,"%s.tmp",dstfilename);

  int  srcfd,dstfd;

  srcfd=dstfd=-1;

  int iFileSize=FileSize(srcfilename);

  int  bytes=0;
  int  total_bytes=0;
  int  onread=0;
  char buffer[5000];

  if ( (srcfd=open(srcfilename,O_RDONLY)) < 0 ) return false;

  if ( (dstfd=open(strdstfilenametmp,O_WRONLY|O_CREAT|O_TRUNC,S_IWUSR|S_IRUSR|S_IXUSR)) < 0) { close(srcfd); return false; }

  while (true)
  {
    memset(buffer,0,sizeof(buffer));

    if ((iFileSize-total_bytes) > 5000) onread=5000;
    else onread=iFileSize-total_bytes;

    bytes=read(srcfd,buffer,onread);

    if (bytes > 0) write(dstfd,buffer,bytes);

    total_bytes = total_bytes + bytes;

    if (total_bytes == iFileSize) break;
  }

  close(srcfd);

  close(dstfd);

  // �����ļ����޸�ʱ������
  char strmtime[21];
  memset(strmtime,0,sizeof(strmtime));
  FileMTime(srcfilename,strmtime);
  UTime(strdstfilenametmp,strmtime);

  if (RENAME(strdstfilenametmp,dstfilename) == false) { REMOVE(strdstfilenametmp); return false; }

  return true;
}


CTimer::CTimer()
{
  memset(&m_start,0,sizeof(struct timeval));
  memset(&m_end,0,sizeof(struct timeval));

  // ��ʼ��ʱ
  Start();
}

// ��ʼ��ʱ
void CTimer::Start()
{
  gettimeofday( &m_start, 0 );
}

// ��������ȥ��ʱ�䣬��λ���룬С���������΢��
double CTimer::Elapsed()
{

  gettimeofday( &m_end, 0 );

  double dstart,dend;

  dstart=dend=0;

  char strtemp[51];
  memset(strtemp,0,sizeof(strtemp));
  snprintf(strtemp,30,"%ld.%ld",m_start.tv_sec,m_start.tv_usec);
  dstart=atof(strtemp);

  memset(strtemp,0,sizeof(strtemp));
  snprintf(strtemp,30,"%ld.%ld",m_end.tv_sec,m_end.tv_usec);
  dend=atof(strtemp);

  // ���¿�ʼ��ʱ
  Start();

  return dend-dstart;
}

