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
        int n;
        string s;
        cin >> n;
        cin >> s;

        map<char, int> myMap;

        for (int i = 0; i < n; i++)
            myMap[s[i]] = -1;

        int minDis = 999999;

        for (int i = 0; i < n; i++)
        {
            if (myMap[s[i]] == -1)
            {
                myMap[s[i]] = i;
            }
            else
            {

                minDis = min(minDis, i - myMap[s[i]]);
                myMap[s[i]] = i;
            }
        }

        if (minDis > n)
            cout << 0 << endl;
        else
            cout << n - minDis << endl;
    }

    return 0;
}