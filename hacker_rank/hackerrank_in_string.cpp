
#include <bits/stdc++.h>
using namespace std;
#define SYNC                          \
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
    SYNC
    int t;

    cin>>t;

    while(t--) {

    string s, m;
    cin >> s;

    m = "hackerrank";

    int match_so_far = 0;
    int n = s.length();

    if (m.length() > n) {
        cout<<"NO"<<endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            if(m[match_so_far] == s[i])
                ++match_so_far;
        }

        if(match_so_far >= m.length())
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
    
    }

    return 0;
}