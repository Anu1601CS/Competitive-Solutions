#include<stdio.h>
#include<string.h>

int main()
{

   int n,i,arr1[100],arr2[100],q,p;
   int count=0,m;
   int j;

   scanf("%d",&n);
   scanf("%d",&p);

   for(i=0;i<p;i++)
   scanf("%d",&arr1[i]);

   scanf("%d",&q);

   for(i=0;i<q;i++)
   scanf("%d",&arr2[i]);

   m=p+q;
   j=0;

   for(i=p;i<m;i++)
   {
     arr1[i]=arr2[j];
     j++;
   }

   for(i=1;i<=n;i++)
   {
     for(j=0;j<m;j++)
     {
       if(i==arr1[j])
       {
         count++;
         break;
       }
     }
   }

   if(count==n)
   printf("I become the guy.");
   else
   printf("Oh, my keyboard!");

   return 0;
}
