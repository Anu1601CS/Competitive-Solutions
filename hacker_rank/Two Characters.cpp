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
    SYNC int l;
    cin >> l;
    string s;
    cin >> s;

    if (l == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    set<char> mySet;
    for (int i = 0; i < l; i++)
        mySet.insert(s[i]);

    set<char>::iterator it1, it2;

    int max = 0;

    for (it1 = mySet.begin(); it1 != mySet.end(); it1++)
    {
        for (it2 = mySet.begin(); it2 != mySet.end(); it2++)
        {
            vector<char> myVec;
            bool flag = true;
            for (int i = 0; i < l; i++)
                if (s[i] == *it1 || s[i] == *it2)
                    myVec.push_back(s[i]);

            for (int i = 0; i < myVec.size() - 1; i++)
                if (myVec[i] == myVec[i + 1])
                    flag = false;

            if (flag && max < myVec.size())
                max = myVec.size();
        }
    }

    cout << max << endl;

    return 0;
}