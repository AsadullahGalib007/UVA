#include <bits/stdc++.h>
#define EPS 1e-9
#define PI 3.141592653589793
#define RAD PI / 180.0
using namespace std;

struct point
{
    double x, y;
    point()
    {
        x = y = 0.0;
    }
    point(double _x, double _y) : x(_x), y(_y) {}

    ///Testing if two points are equal
    bool operator==(point other) const
    {
        return ((fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS));
    }

    ///Sorting the points
    bool operator<(point other) const
    {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
};

///Distance between two points(also called Euclidean distance)
double Euclidean_dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}


int main()
{
    //freopen("920.txt", "r", stdin);
    vector<point>p;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            point _p(x,y);
            p.push_back(_p);
        }

        sort(p.rbegin(), p.rend());
        int MAX = 0;
        double d = 0.0;
        for(int i = 1; i<n; i++)
        {
            if(p[i].y > MAX)
            {
                d += Euclidean_dist(p[i], p[i-1]) *( (p[i].y - MAX) / (p[i].y - p[i-1].y));
                MAX = p[i].y;

            }
        }

        printf("%0.2lf\n",d);
        p.clear();
    }
    return 0;
}
