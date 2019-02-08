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
    SYNC

        list<int>
            l1;

    int n, m, q, a;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        l1.push_back(a);
    }

    for (int i = 0; i < m; i++)
    {
        int popBack = l1.back();
        l1.pop_back();
        l1.push_front(popBack);
    }

    list<int>::iterator it;

    it = l1.begin();

    vector<int> vec(l1.begin(), l1.end());

    // cout<<vec[0];

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        cout << vec[a] << "\n";
    }

    return 0;
}
