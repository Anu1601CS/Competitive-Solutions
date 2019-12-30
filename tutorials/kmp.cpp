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
typedef unsigned long long int ulli;

vector<int>preprocess(string s) 
{
    vector<int>res(s.length());
    int c = 0;

    int i=1, j=0;
    while (i < s.length() && j < i ) {
        if(s[i] == s[j])  {
            res[i] = j + 1;
            ++i;
            ++j;
        } else {
            j = res[j-1];
            if(j == 0) {
                res[i] = 0; 
                ++i;
            }            
        }
    }
    
    return res;
}

int main()
{
    string s,p;
    cin>>s>>p;
    vector<int>pattern;
    pattern = preprocess(p);

    int j =0, i=0;
    while (i<s.length() && j < p.length()) {
            if(s[i] == p[j]) {
                ++i;
                ++j;
            } else {
                if(j!=0) {
                    j = pattern[i];
                } else {
                    i++;
                }
            }
    }

    if(j == p.length())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    

    return 0;
}