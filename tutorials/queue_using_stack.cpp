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
    SYNC int n;

    stack<int> s1, s2;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;

        cin >> val;

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}