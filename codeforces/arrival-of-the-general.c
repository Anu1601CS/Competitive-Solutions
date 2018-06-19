#include<stdio.h>
int main()
{
  int a[100],x=0,count=0,y=0,temp=0,i,j,max=0,min=0,y1=0,n;
  scanf("%d",&n);

  for(i=0;i<n;i++)
  scanf("%d",&a[i]);

  max=a[0];
  min=a[0];
  y = n-1;

  for(i=1;i<n;i++)
  {
    if(max<a[i])
    {
	     max=a[i];
       x=i;
     }
   }

   for(i=1;i<n;i++)
   {
     if(min>=a[i])
     {
       min=a[i];
       y1=i;
       y=n-1-i;
     }
   }

   if(x>y1)
	  printf("%d",x+y-1);
    else
    printf("%d",x+y);

    return 0;
}
