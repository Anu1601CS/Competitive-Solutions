#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int m1,m2;
  cin>>m1>>m2;

  if(0<m1 && 0<m2)
  cout<<0<<" "<<m1+m2<<" "<<m1+m2<<" "<<0;
  else
  if(m1<0 && 0<m2)
  cout<<-(-(m1)+m2)<<" "<<0<<" "<<0<<" "<<-(m1)+m2;
  else
  if(m1<0 && m2<0)
  cout<<m1+m2<<" "<<0<<" "<<0<<" "<<m1+m2;
  else
  if(0<m1 && m2<0)
  cout<<0<<" "<<-(m1-m2)<<" "<<m1-m2<<" "<<0;

  return 0;
}
