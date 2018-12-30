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

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;

int main()
{
    SYNC
    int t;
    cin>>t;

    while(t> 0)
    {
        int i,n,res = 0;
        cin>>n;

        for(i=0; i<=n; i++)
        {
            if(i%2 == 0)
                res = res + 1;
            else
                res = res * 2;

        }
        cout<<res<<endl;

        --t;
    }
    return 0;
}
