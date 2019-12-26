#include<stdio.h>
#include<string.h>

int  main()
{
    int l,i,j;
    char ch[100];
    char ch1[]={'H','Q','9'};
    scanf("%s",ch);
    l=strlen(ch);

    for(i=0;i<3;i++)
    {
      for(j=0;j<l;j++)
      {
        if(ch[j]==ch1[i])
        {
          printf("YES");
          return 0;
        }
      }
    }

    printf("NO");
}
