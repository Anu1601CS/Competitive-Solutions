#include <bits/stdc++.h>
using namespace std;
#define SYNC                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007s
#define all(c) c.begin(), c.end()

typedef long long int lli;

int main()
{
    SYNC
        string s = "abcdefghijklmnopqrstuvwxyz";
    list<char> myList;
    list<char>::iterator it;
    for (int i = 0; i < s.length(); i++)
        myList.push_back(s[i]);

    int n;
    cin >> n;
    string text;
    cin >> text;
    int r;
    cin >> r;

    for (int i = 0; i < r; i++)
    {
        char f = myList.front();
        myList.pop_front();
        myList.push_back(f);
    }

    map<char, char> myMap;

    int c = 0;
    for (it = myList.begin(); it != myList.end(); it++)  
        myMap[s[c++]] = *it;

    for (int i = 0; i < text.length(); i++)
    {
        if(myMap[(char) tolower(text[i])]) {
            
            if(isupper(text[i]))
            cout<<(char)toupper(myMap[(char) tolower(text[i])]);
            else
            cout<<myMap[text[i]];
            
        } else {
            cout<<text[i];
        }
    }

    cout << endl;

    return 0;
}