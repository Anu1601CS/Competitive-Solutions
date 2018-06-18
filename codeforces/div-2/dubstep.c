#include<stdio.h>
#include<string.h>
int main()
{
	char ch1[200],ch2[200];
	int i,n,a,b,c;
	scanf("%s",ch1);
	n=strlen(ch1);

  for(i=0;i<n;i++)
    {
     if(ch1[i]=='W')
     {
       a=1;
       if(ch1[i+1]=='U'&&ch1[i+2]=='B')
       continue;
     }
     if(ch1[i]=='U'&& a==1 && ch1[i-1]=='W')
     {
       b=1;
      continue;
    }

    if(ch1[i]=='B'&& b==1 && ch1[i-1]=='U')
    {
      c+=1;
      if(c==1)
      printf(" ");
      continue;
    }

    printf("%c",ch1[i]);
    a=0;b=0;c=0;
  }
  return 0;
}
