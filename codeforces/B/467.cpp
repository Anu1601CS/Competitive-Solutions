#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SYNC                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'

typedef long long int lli;
typedef unsigned long long int ulli;

vector<int> getBinary(int n)
{
    int i = 0;
    vector<int> binary(32, 0);
    while (n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    return binary;
}

int main()
{
    int n,m,k;
    cin >>n>>m>>k;
    vector<int>type(m+1);
    
    for(int &x: type) {
        cin>>x;
    }

    vector<int>check;
    check = getBinary(type[type.size() -1]);

    int res = 0;
    for(int i=0; i < type.size() - 1; i++) {
        vector<int>binary;
        int d = 0;
        binary = getBinary(type[i]);

        for(int i=0;i<n;i++) {
            if( (check[i] == 1 && binary[i] == 0 ) || (check[i] == 0 && binary[i] == 1 ) ) 
                ++d;
        }

        if(d <= k)
            ++res;

    }

    cout<<res<<endl;

    return 0;
}