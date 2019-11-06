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


int find(vector< pair<lli, lli> > problems){


    vector<lli> fromUp;
    vector<lli> fromDown;

    vector< pair<lli, lli> >::iterator it;

    lli lb = -1;
    lli ub = INF;
    for (it = problems.begin(); it != problems.end(); it++)
    {
        lb = max(lb, it->first);
        ub = min(ub, it->second);

        fromUp.push_back( (ub - lb) + 1 );
    }
    
    lb = -1;
    ub = INF;
    for (lli i = problems.size() - 1; i >= 0 ; i--)
    {
        lb = max(lb, problems[i].first);
        ub = min(ub, problems[i].second);

        fromDown.push_back( (ub - lb) + 1 );
    }

    lli res = -1;

    for(lli i=0; i < fromUp.size() - 1; i++) 
        res = max(res, fromUp[i] + fromDown[fromDown.size()- (i + 2)]);

    return res;
}

bool func(pair<lli, lli> a, pair<lli, lli> b){
    return a.second < b.second;
}

int main()
{
    SYNC lli n;

    cin >> n;
    vector< pair<lli, lli> > problems;

    for (lli i = 0; i < n; i++)
    {
        lli a, b;

        cin >> a >> b;
        problems.push_back(make_pair(a, b));
    }

    sort(problems.begin(), problems.end());

    lli ans1 = find(problems);
    
    sort(problems.begin(), problems.end(), func);

    lli ans2 = find(problems);

    cout<<max(ans1, ans2)<<endl;

    return 0;
}
