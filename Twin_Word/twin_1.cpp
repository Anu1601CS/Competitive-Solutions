#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool checkTwin(string a, string b)
{
    set<char> setA;
    set<char> setB;

    unordered_set<char> vowels;

    vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');

    for (int i = 0; i < a.length(); i++)
        if (vowels.find(toupper(a[i])) == vowels.end())
            setA.insert(toupper(a[i]));

    for (int i = 0; i < b.length(); i++)
        if (vowels.find(toupper(b[i])) == vowels.end())
            setB.insert(toupper(b[i]));

    if (setA == setB)
        return true;

    return false;
}

int main()
{
    string a, b;
    cout << "Enter first word : ";
    cin >> a;
    cout << "\nEnter second word : ";
    cin >> b;

    if (checkTwin(a, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
