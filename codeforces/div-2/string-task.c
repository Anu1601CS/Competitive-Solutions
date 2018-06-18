#include<stdio.h>
#include<string.h>
int main()
{
  int i,j,len,n;
  char s[100];
  gets(s);
  for(len=0;s[len]!='\0';len++);
  for(i=0;i<len;i++)
  {
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'|| s[i]=='y'||s[i]=='Y'||
      s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
      {
        {
          for(j=i;j<len;j++)
          s[j]=s[j+1];
        }
        i--;
      }
    }
    n=strlen(s);
    for(i=0;i<n;i++)
    printf("%c%c",'.',tolower(s[i]));
  }
