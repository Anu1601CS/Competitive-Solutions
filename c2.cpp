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
    lli n;

    cin >> n;
    int count = 0;
    lli ind = 0;
    lli t = sqrt(n);

    for (int i = 2; i <= t; i++)
    {
        if (n % i == 0)
            count++;

        while (n % i == 0)
        {
            n /= i;
            ind = i;
        }
    }

    if (n > 1)
    {
        count++;
        ind = n;
    }
    if (count == 1)
        cout << ind << "\n";
    else
        cout << 1;
    return 0;
}