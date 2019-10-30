#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, string> m;
int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--)
    {
        string name;
        int dd, mm, yyyy;
        cin >> name >> dd >> mm >> yyyy;
        ll age = dd + mm * 100 + yyyy * 1000;
        m[age] = name;
    }
    map<int, string>::iterator itr1, itr2;
    itr1 = m.begin();
    itr2 = m.end();
    itr2--;
    cout << itr2->second << endl<< itr1->second<<endl;
    return 0;
}