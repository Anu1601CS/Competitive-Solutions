#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int min = 9999999;

  sort(arr, arr + n);

  for (int i = 0; i < n; i++)
  {
    if (min > abs(arr[i + 1] - arr[i]))
      min = abs(arr[i + 1] - arr[i]);
  }

  cout << min << endl;

  return 0;
}
