#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, s;
    int m, n;
    cin >> m >> n;
    map<string, int> mp;
    for (int i = 0; i < m; i++)
    {
        string s;
        int t;
        cin >> s >> t;
        //cout << s << "\t" << t << endl;
        mp.insert(make_pair(s, t));
    }
    char ch = getchar();
    while (n--)
    {
        int sum = 0;
        while (getline(cin, s) && s[s.length() - 1 != '.'])
        {
            stringstream ss(s);
            while (ss >> str)
            {
                if (mp[str] != 0)
                    sum += mp[str];
            }
        }
        cout << sum << endl;
    }
    return 0;
    //cout<<str<<endl;
}