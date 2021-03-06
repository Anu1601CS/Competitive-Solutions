#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

  int pos[8][3][3] = {
		{{8,1,6},{3,5,7},{4,9,2}},
		{{4,3,8},{9,5,1},{2,7,6}},
		{{2,9,4},{7,5,3},{6,1,8}},
		{{6,7,2},{1,5,9},{8,3,4}},
		{{6,1,8},{7,5,3},{2,9,4}},
		{{8,3,4},{1,5,9},{6,7,2}},
		{{4,9,2},{3,5,7},{8,1,6}},
		{{2,7,6},{9,5,1},{4,3,8}}
	};

	int arr[3][3],i,k,j;

  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      cin>>arr[i][j];
    }
  }

  int result = 10000;

  for(i =0; i<8; i++)
	{
		int curr = 0;

		for(j = 0; j<3; j++)
		{
			for(k = 0; k<3; k++)
			{
				curr+=abs(pos[i][j][k]-arr[j][k]);
			}
		}
		result = min(result, curr);
	}

  cout<<result;

	return 0;
}
