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

bool myfunction (lli i,lli j) { return (i > j); }
int sti (string s) { stringstream con(s); int x; con >> x; return x; }

int main()
{
  SYNC

  lli i,j,n,m,s;

  while(cin>>n>>m>>s)
  {
    if(n==0 && m ==0 && s==0)
    break;

  lli result = 0;
  string arr[n][m],command,pos;

  string sf;
  char cur;
  int r,c;

  bool visited[n][m];
  for(i=0;i<n;i++)
  {
    cin>>sf;
    for(j=0;j<m;j++)
    {
      if(sf[j] == 'N' || sf[j] == 'S' || sf[j] == 'L' || sf[j] == 'O') { r = i; c = j; pos = cur = sf[j];}

      arr[i][j] = sf[j];
      visited[i][j] = false;
    }
  }

  cin>>command;

  for(i=0;i<s;i++)
  {
    if(command[i] == 'D')
    {
      if(cur == 'N')
        cur = 'L';
      else if(cur == 'S')
        cur = 'O';
      else if(cur == 'L')
      cur = 'S';
      else if(cur == 'O')
      cur = 'N';

    }
    else if(command[i] == 'E')
    {
      if(cur == 'N')
        cur = 'O';
      else if(cur == 'S')
        cur = 'L';
      else if(cur == 'L')
      cur = 'N';
      else if(cur == 'O')
      cur = 'S';

    }
    else if(command[i] == 'F')
    {
      if(cur == 'N' && r-1 >= 0)
      {
        if(arr[r-1][c] == "." || arr[r-1][c] == pos)
        --r;
        else if(arr[r-1][c] == "*")
        {
          --r;
          if(!visited[r][c])
          {
            ++result;
            visited[r][c] = true;
          }
        }

      }
      else if(cur == 'S' && r+1 <= n-1)
      {
        if(arr[r+1][c] == "." || arr[r+1][c] == pos)
        ++r;
        else if(arr[r+1][c] == "*" )
        {
          ++r;
          if(!visited[r][c])
          {
            ++result;
            visited[r][c] = true;
          }
        }
      }
      else if(cur == 'O' && c-1 >= 0 )
      {
        if(arr[r][c-1] == "." || arr[r][c-1] == pos)
        --c;
        else
        if(arr[r][c-1] == "*")
        {
          --c;
          if(!visited[r][c])
          {
            ++result;
            visited[r][c] = true;
          }
        }

      }
      else if(cur == 'L' && c+1 <= m-1)
      {
        if(arr[r][c+1] == "." || arr[r][c+1] == pos )
          ++c;
        else
        if(arr[r][c+1] == "*")
        {
          ++c;
          if(!visited[r][c])
          {
            ++result;
            visited[r][c] = true;
          }
        }
      }
    }
  }

  cout<<result<<endl;
}
  return 0;
}
