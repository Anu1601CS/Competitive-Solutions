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

int main()
{
    SYNC

        int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int count = 1;
        
        int m = arr[0];
        for (int i = 1; i < n; i++)
        {
            // int m = *min_element(arr + max(0, i - 5), arr + (i - 1));

            if (m > arr[i])
                count++;
        }

        cout << count << endl;
    }

    return 0;
}