#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  long long int num;
  cin>>num;

  if(0<num)
  cout<<num;
  else
  {
    long long num1=num;
    int  n1=num1%10;
    num1=num1/10;
    int  n2=num1%10;

    if(abs(n2)<=abs(n1))
    {
      cout<<num1;
    }
    else
    {
      num1=num1/10;
      if(num1!=0)
      cout<<num1<<abs(n1);
      else
      cout<<-(abs(n1));
    }
  }
  return 0;
}
