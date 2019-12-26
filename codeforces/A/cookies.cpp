#include <iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int main()
{
  int n,i,sum=0;
  cin>>n;
  int arr[n];
  int count=0;

  for(i=0;i<n;i++)
  {
    cin>>arr[i];
    sum=sum+arr[i];
  }

  int a;

  for(i=0;i<n;i++)
  {
    a=sum-arr[i];

    if(a%2==0 || a==0)
    count++;
  }
  cout<<count;
  return 0;
}
