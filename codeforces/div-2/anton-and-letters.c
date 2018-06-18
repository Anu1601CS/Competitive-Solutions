#include<stdio.h>
#include<string.h>

int main()
{
    char ch[1000];
    int count=0;
    char ch1[100];
    scanf("%[^\n]%*c",ch);
    int c=0;
    char temp;
    int i,j;

    for(i=0;i<strlen(ch);i++)
    {
      if(ch[i]=='{' || ch[i]==',' || ch[i]==' ' || ch[i]=='}')
      continue;
      else
      {
        ch1[c++] = ch[i];
      }
    }

    for(i=0;i<c;i++)
    {
      for(j=i+1;j<c;j++)
      {
        if(  ch1[i] > ch1[j] )
        {
          temp=ch1[i];
          ch1[i]=ch1[j];
          ch1[j]=temp;
        }
      }
    }

    char match=ch1[0];
    if(c!=0)
    count=1;

    for(i=0;i<c;i++)
    {
      if(match==ch1[i])
      continue;
      else
      {
        count++;
        match=ch1[i];
      }
    }
    printf("%d",count);
}
