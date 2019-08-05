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

    map<int, int> myMap;

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        myMap[a]++;

        if (max < myMap[a])
            max = myMap[a];
    }

    cout<<n - max<<endl;

    return 0;
}