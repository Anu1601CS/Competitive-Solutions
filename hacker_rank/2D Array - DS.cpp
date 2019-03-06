#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

  int arr[6][6];

  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      cin >> arr[i][j];

  int max = -999999;

  for (int i = 1; i < 5; i++)
  {
    for (int j = 1; j < 5; j++)
    {
      int sum = arr[i][j] + arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 1][j + 1] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 1][j + 1];

      if (max < sum)
        max = sum;
    }
  }

  cout << max << endl;
  return 0;
}
