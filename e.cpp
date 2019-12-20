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

int find(int a, int b, int c)
{
    if (a == b)
        return c;

    cout << a << " " << b << endl;

    return min(find(a + c, b, c + 1), find(a, b + c, c + 1));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        cout << find(a, b, 1) << endl;
    }

    return 0;
}