#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x;
    while (cin >> t && t != 0)
    {
        list<int> l1, l2;
        for (int i = 1; i <= t; i++)
            l1.push_back(i);

        while (l1.size() != 1)
        {
            x = l1.front();
            l1.pop_front();
            l2.push_back(x);
            x = l1.front();
            l1.pop_front();
            l1.push_back(x);
        }

        list<int>::iterator itr = l2.begin();
        cout << "Discarded cards:";
        if (l2.size() != 0)
        {
            cout << " " << *itr;
            itr++;
            for (itr; itr != l2.end(); itr++)
            {
                cout << ", " << *itr;
            }
        }
        cout << endl;
        cout << "Remaining card:";
        cout << " " << l1.front() << endl;
    }
    return 0;
}