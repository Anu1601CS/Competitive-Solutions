#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SYNC ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
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
#define all(cc) (cc).begin(),(cc).end()
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;

struct node {
  int maxsum;
  int maxleft;
  int maxright;
  int maxup;
  int maxend;
};

struct node *kad(lli arr[],lli n)
{
  struct node *kadane = (struct node*) malloc(sizeof(struct node));;

  lli max = 0;
  lli maxStart = -1;
  lli maxEnd = -1;
  lli currentStart = 0;
  lli maxSoFar = 0;

  lli i;

  for(i=0;i<n;i++)
  {
    maxSoFar += arr[i];

    if(maxSoFar < 0)
    {
      maxSoFar = 0;
      currentStart = i+1;
    }

    if(max < maxSoFar)
    {
      maxStart = currentStart;
      max = maxSoFar;
      maxEnd  = i;
    }
  }

  kadane->maxsum = max;
  kadane->maxup = maxStart;
  kadane->maxend = maxEnd;

  return kadane;
}

int main()
{
  SYNC

  lli i,j,n;
  lli l,r,k,sumtemp;
  cin>>n;
  lli temp[n];
  lli arr[n][n];

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cin>>arr[i][j];
    }
  }

      struct node *result, *newkadane;

      result = (struct node*) malloc(sizeof(struct node));
      newkadane = (struct node*) malloc(sizeof(struct node));

      result->maxsum = -1;

      for(l=0;l<n;l++)
      {
        for(i=0;i<n;i++)
          temp[i] = 0;

        for(r=l;r<n;r++)
        {
          for(k=0;k<n;k++)
            temp[k] += arr[k][r];

            newkadane = kad(temp,n);

            if(newkadane->maxsum > result->maxsum)
            {
              result->maxsum = newkadane->maxsum;
              result->maxup = newkadane->maxup;
              result->maxend = newkadane->maxend;
              result->maxright = r;
              result->maxleft = l;
            }
        }
      }

cout<<result->maxsum;
return 0;
}
