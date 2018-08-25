#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 100005
const double eps = 1e-7;
const double INF = 1e20;
const double pi = acos (-1.0);
int dcmp (double x)
{
    if (fabs (x) < eps)
        return 0;
    return (x < 0 ? -1 : 1);
}
inline double sqr (double x)
{
    return x*x;
}
struct Point
{
    double x, y;
    Point (double _x = 0, double _y = 0):x(_x), y(_y) {}
    void input ()
    {
        scanf ("%lf%lf", &x, &y);
    }
    void output ()
    {
        printf ("%.2f %.2f\n", x, y);
    }
    bool operator == (const Point &b) const
    {
        return (dcmp (x-b.x) == 0 && dcmp (y-b.y) == 0);
    }
    bool operator < (const Point &b) const
    {
        return (dcmp (x-b.x) == 0 ? dcmp (y-b.y) < 0 : x < b.x);
    }
    Point operator + (const Point &b) const
    {
        return Point (x+b.x, y+b.y);
    }
    Point operator - (const Point &b) const
    {
        return Point (x-b.x, y-b.y);
    }
    Point operator * (double a)
    {
        return Point (x*a, y*a);
    }
    Point operator / (double a)
    {
        return Point (x/a, y/a);
    }
    double len2 () //长度平方
    {
        return sqr (x) + sqr (y);
    }
    double len () //长度
    {
        return sqrt (len2 ());
    }
    Point change_len (double r)//转为长度为r的向量
    {
        double l = len ();
        if (dcmp (l) == 0)
            return *this;
        r /= l;
        return Point (x*r, y*r);
    }
    Point rotate_left ()//顺时针九十度
    {
        return Point (-y, x);
    }
    Point rotate_right () //逆时针九十度
    {
        return Point (y, -x);
    }
    Point rotate (Point p, double ang)  //绕P ANG 度
    {
        Point v = (*this)-p;
        double c = cos (ang), s = sin (ang);
        return Point (p.x + v.x*c - v.y*s, p.y + v.x*s + v.y*c);
    }
    Point normal () //单位法向量
    {
        double l = len ();
        return Point (-y/l, x/l);
    }
};
double cross (Point a, Point b)  //叉乘
{
    return a.x*b.y-a.y*b.x;
}
double dot (Point a, Point b)  //点乘
{
    return a.x*b.x + a.y*b.y;
}
double dis (Point a, Point b)  //距离
{
    Point p = b-a;
    return p.len ();
}
double degree_rad (double ang)  //角度化为弧度
{
    return ang/180*pi;
}
double rad_degree (double rad)  //弧度话角度
{
    return rad/pi*180;
}
double rad (Point a, Point b)  //夹角
{
    return fabs (atan2 (fabs (cross (a, b)), dot (a, b)) );
}
bool parallel (Point a, Point b)  //平行
{
    double p = rad (a, b);
    return dcmp (p) == 0 || dcmp (p-pi) == 0;
}
struct Line
{
    Point s, e;//两个点
    double k;// 角度[-pi,p]
    Line () {}
    Line (Point _s, Point _e)
    {
        s = _s, e = _e;
        k = atan2 (e.y - s.y,e.x - s.x);
    }
//ax+by+c = 0
    Line (double a, double b, double c)
    {
        if (dcmp (a) == 0)
        {
            s = Point (0, -c/b);
            e = Point (1, -c/b);
        }
        else if (dcmp (b) == 0)
        {
            s = Point (-c/a, 0);
            e = Point (-c/a, 1);
        }
        else
        {
            s = Point (0, -c/b);
            e = Point (1, (-c-a)/b);
        }
        get_angle ();
    }
    Line (Point p, double ang)//点斜式
    {
        k = ang;
        s = p;
        if (dcmp (ang-pi/2) == 0)
        {
            e = s + Point (0, 1);
        }
        else
            e = s + Point (1, tan (ang));
    }
    void input ()
    {
        s.input ();
        e.input ();
    }
    void output ()
    {
        printf ("%.2f,%.2f %.2f,%.2f\n", s.x, s.y, e.x, e.y);
    }
    void adjust ()
    {
        if (e < s)
            swap (e, s);
    }
    double length ()  //长度
    {
        return dis (s, e);
    }
    void get_angle ()
    {
        k = atan2 (e.y - s.y,e.x - s.x);
    }
    double angle ()  //倾斜角
    {
        if (dcmp (k) < 0)
            k += pi;
        if (dcmp (k-pi) == 0)
            k -= pi;
        return k;
    }
    Point operator &(const Line &b)const  //直线的焦点（保证存在
    {
        Point res = s;
        double t = (cross (s - b.s, b.s - b.e))/cross (s - e, b.s - b.e
                                                      );
        res.x += (e.x - s.x)*t;
        res.y += (e.y - s.y)*t;
        return res;
    }
};
int relation (Point p, Line l)  //点和直线的关系 -1、左1右0上
{
    int c = dcmp (cross (p-l.s, l.e-l.s));
    if (c < 0)
        return -1;
    else if (c > 0)
        return 1;
    else
        return 0;
}
bool point_on_halfline (Point p, Line l)  //判断点在射线上
{
    int id = relation (p, l);
    if (id != 3)
        return 0;
    return dcmp (dot (p-l.s, l.e-l.s)) >= 0;
}
bool point_on_seg (Point p, Line l)  //判断点在线段上
{
    return dcmp (cross (p-l.s, l.e-l.s)) == 0 &&
           dcmp (dot (p-l.s, p-l.e) <= 0);
}
bool parallel (Line a, Line b)  //直线平行
{
    return parallel (a.e-a.s, b.e-b.s);
}
int seg_cross_seg (Line a, Line v)  //线段相交 1规范 2不规范 3不想交
{
    int d1 = dcmp (cross (a.e-a.s, v.s-a.s));
    int d2 = dcmp (cross (a.e-a.s, v.e-a.s));
    int d3 = dcmp (cross (v.e-v.s, a.s-v.s));
    int d4 = dcmp (cross (v.e-v.s, a.e-v.s));
    if ((d1^d2) == -2 && (d3^d4) == -2)
        return 2;
    return (d1 == 0 && dcmp (dot (v.s-a.s, v.s-a.e)) <= 0) ||
           (d2 == 0 && dcmp (dot (v.e-a.s, v.e-a.e)) <= 0) ||
           (d3 == 0 && dcmp (dot (a.s-v.s, a.s-v.e)) <= 0) ||
           (d4 == 0 && dcmp (dot (a.e-v.s, a.e-v.e)) <= 0);
}
int line_cross_seg (Line a, Line v)  //直线和线段相交判断 a直线v线段 2 规范 1不规范 3不想交
{
    int d1 = dcmp (cross (a.e-a.s, v.s-a.s));
    int d2 = dcmp (cross (a.e-a.s, v.e-a.s));
    if ((d1^d2) == -2)
        return 2;
    return (d1 == 0 || d2 == 0);
}
int line_cross_line (Line a, Line v)  //直线相交 0平行1重合2相交
{
    if (parallel (a, v))
        return relation (a.e, v) == 3;
    return 2;
}
Point line_intersection (Line a, Line v)  {//直线交点（有交点）
    double a1 = cross (v.e-v.s, a.s-v.s);
    double a2 = cross (v.e-v.s, a.e-v.s);
    return Point ((a.s.x*a2-a.e.x*a1)/(a2-a1), (a.s.y*a2-a.e.y*a1)/(a2-
                  a1));
}
int seg_intersectiong (Line a, Line b, Point &p)  //线段交点 0无1规范2不规范（确认只有一个）
{
    int rel = seg_cross_seg (a, b);
    if (rel == 0)
        return 0;
    int cnt = 0;
    if (rel == 1)
    {
        if (point_on_seg (a.e, b))
            p = a.e, cnt++;
        if (point_on_seg (a.s, b))
            p = a.s, cnt++;
        if (point_on_seg (b.e, a))
            p = b.e, cnt++;
        if (point_on_seg (b.s, a))
            p = b.s, cnt++;
        return 2;
    }
    p = line_intersection (a, b);
    return 1;
}
double point_to_line (Point p, Line a)  //点到直线距离
{
    return fabs (cross (p-a.s, a.e-a.s) / a.length ());
}
double point_to_seg (Point p, Line a)  //点到线段距离
{
    if (dcmp (dot (p-a.s, a.e-a.s)) < 0 || dcmp (dot (p-a.e, a.s-a.e))
            < 0)
        return min (dis (p, a.e), dis (p, a.s));
    return point_to_line (p, a);
}
Point projection (Point p, Line a)  //点在直线投影
{
    return a.s + (((a.e-a.s) * dot (a.e-a.s, p-a.s)) / (a.e-a.s).len2()
                 );
}
Point symmetry (Point p, Line a)  //点关于直线对称
{
    Point q = projection (p, a);
    return Point (2*q.x-p.x, 2*q.y-p.y);
}
Line a[1005];
Point b,p1,p2;
int n,m;
int vis[1005];
bool cmp(Line a,Line b)
{
    return a.s.x<b.s.x;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n&&n)
    {
        memset(vis,0,sizeof vis);
        cin>>m>>p1.x>>p1.y>>p2.x>>p2.y;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].s.x>>a[i].e.x;
            a[i].s.y=p1.y;
            a[i].e.y=p2.y;
        }
        sort(a,a+n,cmp);
        for(int i =0;i<m;i++)
        {
            cin>>b.x>>b.y;
            int j;
            for( j=0;j<n;j++)
            {
                if( relation(b,a[j])>0)
                    {++vis[j];break;}
            }
            if(j==n) ++vis[n];
        }
        // for(int i =0;i<=n;i++)cout<<vis[i]<<" ";
       // cout<<endl;
        sort(vis,vis+n+1);
       // for(int i =0;i<=n;i++)cout<<vis[i]<<" ";
        //cout<<endl;
        cout<<"Box"<<endl;
         int ha;
        for(int i =1;i<=m;i++)
        {

            if((ha=upper_bound(vis,vis+n+1,i)-lower_bound(vis,vis+n+1,i))>=1)
                cout<<i<<": "<<ha<<endl;
        }
    }
    return 0;
}
