#include "public.h"

int main()
{
  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);

  vector<int>::iterator p = find_if(a.begin(), a.end(), 3);
  return 0;
}