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
        int total = 0;
        map<int, int> myMap;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a <= 8 && a >= 1)
            {
                if (myMap[a] < b)
                {
                    total += abs(b - myMap[a]);
                    myMap[a] = b;
                }
            }
        }

        cout << total << endl;
    }

    return 0;
}