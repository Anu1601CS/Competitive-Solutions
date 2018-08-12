#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SYNC ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;
lli l,r,x,y;
bool ft(lli a){
	a=a*x;
	if(a<=r && a>=l) return 1;
	return 0;
}

bool visited[100000]={false};

int bsf(vector<pair<int,int>> vecp[], int s, int n)
{
	int dist[n],i;

	for(i=1;i<=n;i++)
	dist[i] = 100005;

	list<int> que;
	vector<pair<int,int>>::iterator itv;

	que.push_back(s);
	dist[s] = 0;

	while(!que.empty())
	{
		int v = que.front();
		que.pop_front();

		for(itv= vecp[v].begin(); itv != vecp[v].end(); itv++)
		{
			if(dist[itv->first] > dist[v] + itv->second)
			{
				dist[itv->first] = dist[v] + itv->second;

				que.push_back(itv->first);
			}
		}
	}

	 for (int i=1; i<=n; i++)
	 {
		 if( i==s )
		 continue;

		 if(dist[i]!=0 && dist[i]!=100005)
		 cout<<dist[i]<<" ";
		 else
		 cout<<-1<<" ";
	 }

	 cout<<endl;

	 return 0;
}

int main()
{
  SYNC

	int query;
	cin>>query;

	int n,m,s,u,v,i;
	while(query>0)
	{
		cin>>n>>m;

		vector<pair<int,int>> vecp[100005];

		for(i=0; i<m; i++)
		{
			cin>>u>>v;
			vecp[u].push_back(make_pair(v,6));
			vecp[v].push_back(make_pair(u,6));
		}

		cin>>s;
		bsf(vecp,s,n);

		--query;
	}


  return 0;
}
