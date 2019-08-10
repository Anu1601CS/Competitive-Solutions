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

        string s;
    cin >> s;

    int res = 0;

    for (int i = 0; i < s.length(); i = i + 3)
    {
        if (s[i] != 'S')
            ++res;
        if (s[i + 1] != 'O')
            ++res;
        if (s[i + 2] != 'S')
            ++res;

        // cout << s[i]
    }

    cout << res << endl;

    return 0;
}