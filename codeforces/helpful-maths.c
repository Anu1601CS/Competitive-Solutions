#include<stdio.h>
#include<string.h>
int main()
{
  int n,i,j,temp,a=-1;
  char ch[100],ch1[100];
  gets(ch);
  n=strlen(ch);
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(ch[i]>ch[j])
      {
        temp=ch[i];
        ch[i]=ch[j];
        ch[j]=temp;
      }
    }
  }

  for(i=0;i<n;i++)
  {
    if(ch[i]!='+')
    {
      printf("%c",ch[i]);
      if(i<n-1)
      printf("%c",'+');
    }
    else
    continue;
  }
}
