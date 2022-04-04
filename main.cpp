/*******************************************************************************
> File Name: main.cpp
> Author: camelot
> mail: 1420494366@qq.com
> Created Time: 2022年04月04日 星期一 14时11分29秒
> Message: 
********************************************************************************/
#include "public.h"

bool IsOdd(int i)
{
  return ((i % 2) == 1);
}

int main()
{
  std::vector<int> myvector;

  printf("hello\n");
  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);

  std::vector<int>::iterator it = std::find_if(myvector.begin(), myvector.end(), IsOdd);
  std::cout << "The first odd value is " << *it << '\n';

  return 0;
}
