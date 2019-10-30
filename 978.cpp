#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int bl, g, b;
        cin >> bl >> g >> b;
        priority_queue<int> q1, q2, q3, q4;
        while (g--)
        {
            int m;
            cin >> m;
            q1.push(m);
        }
        while (b--)
        {
            int m;
            cin >> m;
            q2.push(m);
        }
        while (!q1.empty() && !q2.empty())
        {
            int _min = min(q1.size(), q2.size());
            _min = min(bl, _min);
            for (int i = 0; i < _min; i++)
            {
                int x = q1.top();
                q1.pop();
                int y = q2.top();
                q2.pop();

                q3.push(x);
                q4.push(y);
            }
            while(!q3.empty() && !q4.empty())
            {
                int x = q3.top();
                q3.pop();
                int y = q4.top();
                q4.pop();
                if (x > y)
                {
                    x -= y;
                    q1.push(x);
                }

                else if (y > x)
                {
                    y -= x;
                    q2.push(y);
                }
            }
        }
        if (q1.size() == 0 && q2.size() == 0)
        {
            cout << "green and blue died" << endl;
        }
        else
        {
            if (q1.size() > 0)
            {
                cout << "green wins" << endl;
                while (!q1.empty())
                {
                    int x = q1.top();
                    q1.pop();
                    cout << x << endl;
                }
            }
            else if (q2.size() > 0)
            {
                cout << "blue wins" << endl;
                while (!q2.empty())
                {
                    int x = q2.top();
                    q2.pop();
                    cout << x << endl;
                }
            }
        }
        if (t)
            cout << endl;
    }
    return 0;
}