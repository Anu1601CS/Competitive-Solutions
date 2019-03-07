#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> count;
  count.assign(999999, 0);

  int arr[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int max = -999999;

  for (int i = 0; i < n; i++)
  {
    count[arr[i]]++;

    if (max < arr[i])
      max = arr[i];

    if (count[arr[i]] > 1)
    {
      max = max + 1;
      arr[i] = max;
    }
  }

  for (auto i : arr)
    cout << i << " ";

  return 0;
}
