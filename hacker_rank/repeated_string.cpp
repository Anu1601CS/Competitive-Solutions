#include <bits/stdc++.h>
using namespace std;
#define SYNC                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007s
#define all(c) c.begin(), c.end()

typedef long long int lli;

int main()
{
    string s;
    cin>>s;
    lli l = s.length();
  

    lli count = 0;

    for(int i=0;i<l;i++)    
        if(s[i] == 'a') 
            ++count;

    lli n;
    cin>>n;

    lli ans;
    ans = count * (n/l);

    for(int i=0; i<(n%l); i++)
        if(s[i] == 'a')
            ans = ans +1;

cout<<ans<<endl;

}