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

int main()
{
    int k;
    cin >> k;

    while (k--)
    {
        int n;
        cin >> n;

        string s, t;

        cin >> s >> t;

        int co = 0;
        char a, b, c, d;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {

                ++co;

                if (co == 1)
                {
                    a = s[i];
                    b = t[i];
                }

                if (co == 2)
                {
                    c = s[i];
                    d = t[i];
                }
            }
        }

        if (co == 0)
            cout << "YES";
        else if (co == 2 && a == c && d == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}