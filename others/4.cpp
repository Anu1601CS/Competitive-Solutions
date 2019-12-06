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
    lli n, m;
    cin >> n >> m;

    lli arr[n];
    lli temp[n];
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    vector<pair<lli, lli>> myVec;

    for (lli i = 0; i < n; i++)
    {
        while (temp[i] != 0)
        {
            lli x1 = temp[i];
            pair<lli, lli> p1;
            p1.first = x1 - (x1 / 2);
            p1.second = i;
            myVec.push_back(p1);
            temp[i] /= 2;
        }
    }

    sort(myVec.begin(), myVec.end());

    lli j = 0;
    for (lli i = myVec.size() - 1; i >= 0; i--)
    {
        if (j >= m)
            break;
        else
        {
            arr[myVec[i].second] -= myVec[i].first;
        }

        j++;
    }

    lli sum = 0;

    for (lli i = 0; i < n; i++)
        sum += arr[i];

    cout << sum << endl;

    return 0;
}
