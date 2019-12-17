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

lli fac(lli n)
{
    if (n <= 1)
        return 1;

    return (n * fac(n - 1)) % mod;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        int n;
        cin >> n;
        cin >> a >> b;

        int CA1 = 0, CA0 = 0, CB1 = 0, CB0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
                CA1++;
            else
                CA0++;

            if (b[i] == '1')
                CB1++;
            else
                CB0++;
        }

        if (CA0 == CB0 && CA1 == CB1)
        {
            cout << fac(n) << endl;
        }
        else if ((CA0 == n || CA1 == n) && (CB0 == n || CB1 == n))
        {
            cout << 1 << endl;
        }
        else if (CA0 == n || CA1 == n)
        {
            cout << fac(n) << endl;
        }
        else if (CB0 == n || CB1 == n)
        {
            cout << fac(n) << endl;
        }
        else
        {
            cout << (fac(n) * fac(n)) % mod << endl;
        }
    }

    return 0;
}