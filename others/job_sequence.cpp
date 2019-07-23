#include <bits/stdc++.h>
using namespace std;
#define SYNC                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second

typedef long long int lli;

struct Node
{
  char id;
  int dead;
  int profit;
};

bool com(struct Node *a, struct Node *b)
{
  return (a->profit > b->profit);
}

int main()
{
  SYNC

      vector<struct Node *>
          jobs;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    struct Node *job = (struct Node *)malloc(sizeof(struct Node));
    cin >> job->id;
    cin >> job->dead;
    cin >> job->profit;

    jobs.push_back(job);
  }

  sort(jobs.begin(), jobs.end(), com);

  array<bool, 1000> time;
  array<char, 1000> sequence;

  time.fill(false);

  int profit = 0;

  for (auto j : jobs)
  {
    for (int i = j->dead; i >= 1; i--)
    {
      if (!time[i])
      {
        sequence[i] = j->id;
        time[i] = true;
        profit += j->profit;
        break;
      }
    }
  }

  for (int i = 1; i < n; i++)
    if (time[i])
      cout << sequence[i] << " ";
  cout << profit << endl;

  return 0;
}
