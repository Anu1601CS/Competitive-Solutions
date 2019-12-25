
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

bool check(int n)
{
    int c = 0;

    for (int i = 2; i <= n; i++)
    {

        if (n == i)
            continue;

        if (c > 2)
            return true;

        if (n % i == 0)
            ++c;
    }

    return false;
}

int main()
{

    lli n;
    cin >> n;

    for (lli p = 2;; p++)
    {
        if (check(p))
        {
            if (check(n + p))
            {
                cout << n + p << " " << p << endl;
                break;
            }
        }
    }

    return 0;
}