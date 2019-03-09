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

    int i = 0;
    int b = n - 1;

    while (i < n && i < b)
    {
      if (arr[i] == 0)
      {
        if (arr[b] != 0)
        {
          swap(arr[i], arr[b]);
          i++;
        }
        b--;
      }
      else
      {
        i++;
      }
    }

    for (auto i : arr)
      cout << i << " ";
  }

  return 0;
}
