#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    int maxe = arr[n - 1];

    stack<int> ans;
    for (int i = n - 2; i >= 0; i--)
    {
      ans.push(max(arr[i + 1], maxe));
      maxe = max(arr[i + 1], maxe);
    }

    while (!ans.empty())
    {
      cout << ans.top() << " ";
      ans.pop();
    }
  }
  return 0;
}
