#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    while (cin >> t && t != EOF)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isS = true, isP = true, isQ = true;
        while (t--)
        {
            int x, y;
            cin >> x >> y;
            switch (x)
            {
            case 1:
            {
                if (isS)
                    s.push(y);

                if (isP)
                    pq.push(y);

                if (isQ)
                    q.push(y);
                break;
            }

            case 2:
            {
                if (isS)
                {
                    if (s.empty() || s.top() != y)
                        isS = false;
                    else
                        s.pop();
                }

                if (isQ)
                {
                    if (q.empty() || q.front() != y)
                        isQ = false;
                    else
                        q.pop();
                }

                if (isP)
                {
                    if (pq.empty() || pq.top() != y)
                        isP = false;
                    else
                        pq.pop();
                }
                break;
            }
            }
        }

        if (isS == true && isP == false && isQ == false)
            cout << "stack" << endl;
        else if (isS == false && isP == true && isQ == false)
            cout << "priority queue" << endl;
        else if (isS == false && isP == false && isQ == true)
            cout << "queue" << endl;
        else if (isS == false && isP == false && isQ == false)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;
    }
    return 0;
}