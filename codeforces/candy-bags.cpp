#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int c1=0;

int main()
{
	int m,n,i;
	cin>>m;
	n=(m*m)/2;

	for(i=0;i<n;i++)
	{
    cout<<i+1<<" "<<(m*m)-i<<" ";
    c1++;
    if(c1%(m/2)==0)
    cout<<"\n";
  }
  return 0;
}
