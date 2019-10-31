
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
    ifstream file("input_3.txt");
    string str;
    vector<string> myVec;

    while (getline(file, str))
        myVec.push_back(str);

    vector<string>::iterator it1, it2, it3, it4;

    cout << "Set of twin pairs : " << endl;

    for (it1 = myVec.begin(); it1 != myVec.end(); it1++)
    {

        for (it2 = it1; it2 != myVec.end(); it2++)
        {
            if (it1 == it2)
                continue;

            string s1 = *it1;
            vector<string> p1;
            istringstream iss1(s1);
            for (string s1; iss1 >> s1;)
                p1.push_back(s1);

            string s2 = *it2;
            vector<string> p2;
            istringstream iss2(s2);
            for (string s2; iss2 >> s2;)
                p2.push_back(s2);

            int count = 0;
            bool first = false;
            bool second = false;

            for (int i = 0; i < p1.size(); i++)
            {
                for (int j = 0; j < p2.size(); j++)
                {
                    if (checkTwin(p1[i], p2[j]))
                    {
                        ++count;
                        break;
                    }
                }
            }

            if (p1.size() <= count)
                first = true;

            count = 0;

            for (int i = 0; i < p2.size(); i++)
            {
                for (int j = 0; j < p1.size(); j++)
                {
                    if (checkTwin(p2[i], p1[j]))
                    {
                        ++count;
                        break;
                    }
                }
            }

            if (p2.size() <= count)
                second = true;

            if (first && second)
                cout << *it1 << " <------> " << *it2 << endl;
        }
    }

    return 0;
}
