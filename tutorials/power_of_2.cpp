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
#define endl '\n'

typedef long long int lli;

int nextPowerOfTwo(int n)
{
    int val = 1;

    while (val <= n)
        val = val << 1;

    return val;
}

int prevPowerOfTwo(int n)
{
    int c = 0;
    while (pow(2, c) < n)
        c++;

    if (pow(2, c) == n)
        return pow(2, c - 1);
    else
        return pow(2, c);
}

int main()
{
    SYNC

            cout
        << nextPowerOfTwo(8) << endl;
    cout << prevPowerOfTwo(8) << endl;

    return 0;
}