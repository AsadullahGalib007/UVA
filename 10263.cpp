#include <bits/stdc++.h>
#define INF 1e9
#define EPS 1e-9
#define PI 3.141592653589793
#define RAD PI/180.0
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

struct vec
{
    double x,y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)  ///convert 2 points to vector a->b
{
    return vec(b.x-a.x, b.y-a.y);
}

vec scale(vec v, double s)
{
    return vec(v.x*s, v.y*s);
}

point translate(point p, vec v)
{
    return point(p.x+v.x, p.y+v.y);
}

double dot(vec a, vec b)
{
    return (a.x*b.x + a.y*b.y);
}
double norm_sq(vec v)
{
    return (v.x*v.x + v.y*v.y);
}
double PointToLine(point p, point a, point b, point &c)
{
    ///formula: c = a + u*ab
    vec ap = toVec(a,p), ab = toVec(a,b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab,u));
    return Euclidean_dist(p,c);
}

double PointToSegment(point p, point a, point b, point &c)
{
    ///b=c
    vec ap = toVec(a,p), ab = toVec(a,b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u<0.0)
    {
        c = point(a.x, a.y);
        return Euclidean_dist(p,a);
    }

    if(u>1.0)
    {
        c = point(b.x, b.y);
        return Euclidean_dist(p,b);
    }
    return PointToLine(p,a,b,c);
}

int main()
{
    vector<point>p;
    freopen("10263.txt", "r", stdin);
    double x,y;
    int n;
    while(scanf("%lf\n%lf\n%d",&x,&y,&n) != EOF)
    {
        point _p(x,y), c;
        for(int i=0; i<n+1; i++)
        {
            double m,n;
            scanf("%lf\n%lf",&m,&n);
            point x(m,n);
            p.push_back(x);
        }
        double ans = INF;
        point sol;
        for(int i=0; i<n; i++)
        {
            double dist = PointToSegment(_p,p[i],p[i+1],c);
            if(dist<ans)
            {
                ans = dist;
                sol = c;
            }
        }
        printf("%0.4lf\n%0.4lf\n",sol.x,sol.y);
        p.clear();
    }
    return 0;
}


