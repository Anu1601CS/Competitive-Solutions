#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <thread>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
  long long int num,find;
  long long int a=0;

  cin>>num>>find;
  if(num%2==0)
  {
    if(find<=num/2)
    {
      a=2*find-1;
      cout<<a;
      return 0;
    }
    else
    {
      find=(find-num/2);
      a=2*find;
      cout<<a;
      return 0;
    }
  }
  else
  {
    if(find<=(num/2)+1)
    {
      a=2*find-1;
      cout<<a;
      return 0;
    }
    else
    {
      find=(find-(num/2+1));
      a=2*find;
      cout<<a;
      return 0;
    }
  }

  return 0;
}
