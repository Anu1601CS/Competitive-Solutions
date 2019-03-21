#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fun(int arr[], int t, int calsum, int sum)
{

  if (t == 0)
    return abs((sum - calsum) - calsum);

  return min(fun(arr, t - 1, calsum + arr[t - 1], sum), fun(arr, t - 1, calsum, sum));
}

int main()
{

  int t;
  cin >> t;

  int sum = 0;
  int arr[t];

  for (int i = 0; i < t; i++)
  {
    cin >> arr[i];
    sum = sum + arr[i];
  }

  cout << fun(arr, t, 0, sum);
  return 0;
}
