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

    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> myStack;

    myStack.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        while (!myStack.empty() && myStack.top() < arr[i])
        {
            cout << myStack.top() << "-->" << arr[i] << endl;
            myStack.pop();
        }

        myStack.push(arr[i]);
    }

    while (!myStack.empty())
    {
        cout << myStack.top() << "-->" << "-1"<< endl;
        myStack.pop();
    }

    return 0;
}