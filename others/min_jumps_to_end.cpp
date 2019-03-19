#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinJump(int arr[], int n)
{
  vector<int> vec(n, 999999);

  vec[0] = 0;

  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (arr[j] >= (i - j))
        vec[i] = min(vec[i], vec[j] + 1);

  cout << vec[n - 1];

  return 0;
}

int main()
{
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  findMinJump(arr, n);

  return 0;
}
