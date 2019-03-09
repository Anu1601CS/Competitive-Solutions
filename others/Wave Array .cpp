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

    for (int i = 1; i < n - 1; i += 2)
    {
      if (arr[i - 1] < arr[i])
        swap(arr[i - 1], arr[i]);
    }

    for (auto i : arr)
      cout << i << " ";

      cout<<endl;
  }

  return 0;
}
