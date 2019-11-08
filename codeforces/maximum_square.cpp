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
    int n;
    cin >> n;

    while (n--)
    {
        int k;
        cin >> k;
        vector<int> myVec;
        for (int i = 0; i < k; i++)
        {
            int a;
            cin >> a;
            myVec.push_back(a);
        }

        sort(myVec.begin(), myVec.end());

        int tmin = 99999999;
        int ans = 0;
        for (int i = k; i >= 0; i--)
        {
            tmin = min(tmin, myVec[i - 1]);
            int s = k - i + 1;
            if (s <= tmin)
                ans = s;
        }

        cout << ans << endl;
    }
    return 0;
}