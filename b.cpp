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
    SYNC int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int t = n;

    sort(arr, arr + n);

    while (t--)
    {
        int op = 0;
        auto min = upper_bound(arr, arr + n, 0);

        int m = *min;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                arr[i] = arr[i] - m;
                ++op;
            }
        }

        if (op != 0)
            cout << op << endl;
    }

    return 0;
}