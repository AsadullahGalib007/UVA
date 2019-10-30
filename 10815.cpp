#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m;
    string str, s;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            int x = int(str[i]);
            if (!isalpha(str[i]) && x != 32)
            {
                str[i] = ' ';
                i = 0;
            }

            if (isalpha(str[i]))
            {
                str[i] = tolower(str[i]);
            }
        }
        stringstream ss(str);
        while (ss >> s)
        {
            m[s]++;
        }
    }
    map<string, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << endl;
    }
    return 0;
}