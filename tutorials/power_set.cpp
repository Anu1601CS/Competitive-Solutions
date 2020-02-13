#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SYNC                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'

typedef long long int lli;

int main()
{

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	vector<vector<int>> ans;

		int n = nums.size();
		int N = (1<<n);

		cout<<N<<endl;
    
		vector<int> tmp;

		for(int i=0;i<N;i++) {
			tmp.clear();
			for(int j=0;j<n;j++) {
				if((i & (1<<j)) != 0)
				   tmp.push_back(nums[j]);
			}
			ans.push_back(tmp);
		}


		for(int i=0;i<nums.size(); i++ ){
			for(int j=0;j<ans[i].size(); j++) {
				cout<<ans[i][j]<<" ";
		}

			cout<<endl;
		}
	return 0;
}