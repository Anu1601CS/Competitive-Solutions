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
lli l,r,x,y;
bool ft(lli a){
	a=a*x;
	if(a<=r && a>=l) return 1;
	return 0;
}

int main()
{
  SYNC
  long long int n,k,i,count = 0;
  long long int ch = 0;
  cin>>n>>k;

  string s;
  cin>>s;

  //s.resize();
  if(s.length() == 1 && k >= 1)
  {
    cout<<"9";
    return 0;
  }
  else if(k==0)
  {
    cout<<s;
    return 0;
  }

  for(i=0; i<n/2; i++)
    if(s[i] != s[(n-1)-i])
      ++count;

  if(count > k)
  {
    cout<<"-1";
    return 0;
  }

  long long int ext = k-count;

  for(i=0;i<n/2; i++)
  {
    if(s[i] == '9' && s[(n-1)-i] == '9')
    {
      continue;
    }
    else if(s[i] == '9' || s[(n-1)-i] == '9')
    {
        s[i] = '9';
        s[(n-1)-i] = '9';
      }
      else
      {
        if(ext>=1)
        {
          if(s[i] == s[(n-1)-i])
          {
            ext = ext-2;
          }
          else
          {
            --ext;
          }
          s[i] = '9';
          s[(n-1)-i] = '9';

        }
        else
        {
        if(s[i] > s[(n-1)-i])
          s[(n-1)-i] = s[i];
          else
          s[i] = s[(n-1)-i];
        }
      }
  }

for(i=0; i<n; i++)
cout<<s[i];

  return 0;
}
