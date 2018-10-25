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

    typedef long long int lli;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<bool> vb;
    typedef vector<vector<int> > vvi;
    typedef vector<long long int> vlli;
    typedef vector<pair<int,int> > vpii;

    bool myfunction (lli i,lli j) { return (i > j); }
    int sti (string s) { stringstream con(s); int x; con >> x; return x; }

    int main()
    {
      SYNC
      int t;
      cin>>t;

      while(t>0)
      {
        lli n;
        cin>>n;

        lli arr[n];

        for(lli i=0;i<n;i++)
          cin>>arr[i];


        lli fl=0,fh,flag=1,re=1;

        for(lli i=0;i<n-1;i++)
        {
          if(flag)
          {
            if(arr[i]<=arr[i+1])
            {
              fh = i;
            }
            else
            {
              flag = 0;
              continue;
            }
          }

          if(!flag)
          {
            if(arr[i] <= arr[i+1])
            {
              continue;
            }
            else
            {
              cout<<"NO"<<endl;
              re = 0;
              break;
            }
          }
        }

        if(flag)
        {
          cout<<"YES"<<endl;
        }
        else if(re)
        {
          if(arr[n-1] <= arr[0])
          cout<<"YES"<<endl;
          else
          cout<<"NO"<<endl;
        }

        --t;
      }
      return 0;
    }
