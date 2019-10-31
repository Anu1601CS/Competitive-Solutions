
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;

bool checkRelation(vector< pair<char, char> > relation, char a, char b)
{
    vector< pair<char, char> >::iterator it1, it2;

    int f1 = false, f2 = false;

    for (it1 = relation.begin(); it1 != relation.end(); it1++)
    {
        if (it1->first == a && it1->second == b)
        {
            f1 = true;
            break;
        }
    }

    for (it2 = relation.begin(); it2 != relation.end(); it2++)
    {
        if (it2->first == b && it2->second == a)
        {
            f2 = true;
            break;
        }
    }

    if (f1 && f2)
        return true;

    return false;
}

int main()
{
    ifstream file("input.txt");
    string str;
    vector<string> myVec;

    while (getline(file, str))
        myVec.push_back(str);

    vector<string>::iterator it1, it2;

    cout << "Set of groups: " << endl;

    set<char> users, group;
    vector< pair<char, char> > relation;

    bool grouped[999999];

    for (it1 = myVec.begin(); it1 != myVec.end(); it1++)
    {
        string s1 = *it1;
        vector<string> p1;
        istringstream iss1(s1);
        for (string s1; iss1 >> s1;)
            p1.push_back(s1);

        char a = p1[p1.size() - 2][0];
        char b = p1[p1.size() - 1][0];
        users.insert(a);
        users.insert(b);

        grouped[a] = false;
        grouped[b] = false;

        relation.push_back(make_pair(a, b));
    }

    set<char>::iterator it3, it4, it5, it6;

    for (it3 = users.begin(); it3 != users.end(); it3++)
    {
        if (grouped[*it3])
            continue;

        group.insert(*it3);

        for (it4 = users.begin(); it4 != users.end(); it4++)
        {
            if (it3 == it4)
                continue;

            if (checkRelation(relation, *it3, *it4))
            {
                int count = 0;

                for (it5 = group.begin(); it5 != group.end(); it5++)
                {
                    if (*it5 == *it3)
                        continue;

                    if (checkRelation(relation, *it5, *it4))
                    {
                        ++count;
                    }
                }

                if (count == group.size() - 1)
                    group.insert(*it4);
            }
        }

        if (group.size() >= 3)
        {
            std::ofstream out("output.txt", ios::app);
            string str = "";
            for (it6 = group.begin(); it6 != group.end(); it6++)
            {
                grouped[*it6] = true;
                
                str = str +  *it6 + "@toppr.com, ";

                cout << *it6 << "@toppr.com,"
                     << " ";
            }
            
            out << str + "\n";
            cout << endl;
            out.close();
        }

        group.clear();
    }

    return 0;
}
