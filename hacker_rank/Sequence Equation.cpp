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
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int, int>> vpii;

int main()
{
    SYNC int n;

    cin >> n;

    int p[n];
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<int> vec;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[p[j]] == i)
            {
                vec.push_back(j);
                break;
            }
        }
    }

    vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
        cout << *it <<endl;

    return 0;
}
