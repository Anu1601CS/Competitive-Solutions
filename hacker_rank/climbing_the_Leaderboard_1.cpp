#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,m,temp,i, count = 0;

  vector<int>::iterator it1, it2;

  vector<int> scores;
  vector<int> alice;

  cin>>n;

  for(i=0; i<n; i++)
  {
    cin>>temp;
    scores.push_back(temp);
  }

  cin>>m;

  for(i=0; i<m; i++)
  {
    cin>>temp;
    alice.push_back(temp);
  }

  sort(scores.begin(), scores.end());

  scores.erase( unique( scores.begin(), scores.end()), scores.end());

  for(it1 = alice.begin(); it1 != alice.end(); it1++)
  {
    count = 0;

    for(it2 = scores.begin(); it2 != scores.end(); it2++)
    {
      count++;

      if(*it1 <= *it2)
      {
        temp = scores.size() - (it2-scores.begin());

        if(*it1 == *it2)
        {
          cout<<temp<<endl;
          break;
        }

        cout<<temp+1<<endl;
        break;
      }
      else if(count == scores.size())
      {
        cout<<1<<endl;
      }
    }
  }

  return 0;
}
