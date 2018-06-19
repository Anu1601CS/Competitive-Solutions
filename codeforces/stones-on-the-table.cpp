#include<bits/stdc++.h>
using namespace std;

int main()
{
   char ch[1000];
   int n;
   int count=0;
   int i;

   cin>>n;

   for(i=0;i<n;i++)
   cin>>ch[i];

   for(i=0;i<n;i++)
   {
     if(ch[i]==ch[i+1])
     count++;
   }
   cout<<count;
 }
