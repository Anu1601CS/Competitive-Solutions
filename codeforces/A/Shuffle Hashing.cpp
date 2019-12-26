

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
        string p, h;
        cin >> p >> h;

        map<char, int> myMap;
        map<char, int>::iterator it;

        for (int i = 0; i < p.length(); i++)
            myMap[p[i]]++;

        int flag = 0;
        for (int i = 0; i < h.length(); i++)
        {
            map<char, int> myMapH;

            int k = i, l = i + p.length();

            if (l > h.length())
                break;

            while (k < l)
            {
                myMapH[h[k]]++;
                k++;
            }

            for (it = myMap.begin(); it != myMap.end(); it++)
            {
                if (myMapH[it->first] != it->second)
                    break;
            }

            if (it == myMap.end())
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            cout << "NO" << endl;
    }

    return 0;
}