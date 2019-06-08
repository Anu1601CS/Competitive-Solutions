    #include <bits/stdc++.h>
    #include <string>
    using namespace std;
    #define SYNC ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    #define DEBUG(x) cout << '>' << #x << ':' << x << endl;
    #define inf 0x3f3f3f3f
    #define INF 1000111000111000111LL
    #define mod 1000000007
    #define pi acos(-1.0)
    #define eps 1e-8
    #define endl '\n'


    typedef long long int lli;

    int main()
    {
        SYNC

        int n,k;
        int e = 100;
        cin>>n>>k;
        
        int c[n];

        for(int i=0;i<n;i++)
        cin>>c[i];

        int i=0;    

        while(1)
        {
            i = (i+k) % n;
            
            if(c[i] == 1)
            e = e - 2;
            
            e = e - 1;

            if(i == 0)
                break;

        }

        cout<<e<<endl;

        return 0;
    }
