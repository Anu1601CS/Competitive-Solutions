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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int c0 = 0, c2 = 0;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            if (a == 0)
                ++c0;

            if (a == 2)
                ++c2;
        }

        cout << (c0 * (c0 - 1)) / 2 + (c2 * (c2 - 1)) / 2 << endl;
    }

    return 0;
}