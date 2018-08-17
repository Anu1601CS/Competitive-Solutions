#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,rank,score;
    cin>>n;

    set<int> scores;

    for(int i=0;i<n;++i)
    {
        cin>>score;
        scores.insert(score);
    }

    set<int>::iterator it = scores.begin();
    rank = scores.size() + 1;
    cin>>m;

    while(m--)
    {
      cin>>score;

      while(*it<=score && it!=scores.end())
      {
        ++it;
        --rank;
      }

      cout<<rank<<endl;
    }
    return 0;
}
