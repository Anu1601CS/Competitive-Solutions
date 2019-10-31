
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
    ifstream file("input_2.txt");
    string str;
    vector<string> myVec;

    while (getline(file, str))
        myVec.push_back(str);

    vector<string>::iterator it1, it2;

    cout << "Set of twin pairs : " << endl;

    for (it1 = myVec.begin(); it1 != myVec.end(); it1++)
    {

        for (it2 = it1; it2 != myVec.end(); it2++)
        {
            if (it1 == it2)
                continue;
            if (checkTwin(*it1, *it2))
                cout << *it1 << " " << *it2 << endl;
        }
    }

    return 0;
}
