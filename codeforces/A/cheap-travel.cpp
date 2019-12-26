#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,a,b,v;
    int  cost=0,cost2,cost1;
    int a1,a2;

    cin>>n>>m>>a>>b;

     if( (float)b/m >a )
     {
     	cout<<n*a;
     }
      else
     if((float)b/m<a)
     {
     	 if(n%m==0)
       {
         cout<<n*(float)b/m;
       }
       else
       {
         v=n%m;
         cost1=(float)b/m*(n-v);

         if(v<=m)
          a1=b;
          a2=v*a;
          cost2=a1<a2?a1:a2;
          cout<<cost1+cost2;
        }
      }
      else
      if((float)b/m==a)
      {
        cout<<n*a;
      }

      return 0;
}
