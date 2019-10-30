#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll m, n;
    while (cin >> m >> n)
    {
        ll count = 0;
        if (m != 0 && n != 0)
        {
            vector<ll> s1, s2;
            for (ll i = 0; i < m; i++)
            {
                ll p;
                cin >> p;
                s1.push_back(p);
            }
            for (ll i = 0; i < n; i++)
            {
                ll q;
                cin >> q;
                s2.push_back(q);
            }
            int i=0, j=0;
            while (i < n && j < m)
            {
                while (j < m && s2[j] < s1[i])
                    j++;
                if (j > m)
                    break;
                if (s1[i] == s2[j])
                {
                    count++;
                    j++;
                }
                i++;
            }
            cout << count << endl;
        }
        else
            break;
    }
    return 0;
}