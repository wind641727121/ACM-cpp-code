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
int flag=1;
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
    double len2 () //����ƽ��
    {
        return sqr (x) + sqr (y);
    }
    double len () //����
    {
        return sqrt (len2 ());
    }
    Point change_len (double r)//תΪ����Ϊr������
    {
        double l = len ();
        if (dcmp (l) == 0)
            return *this;
        r /= l;
        return Point (x*r, y*r);
    }
    Point rotate_left ()//˳ʱ���ʮ��
    {
        return Point (-y, x);
    }
    Point rotate_right () //��ʱ���ʮ��
    {
        return Point (y, -x);
    }
    Point rotate (Point p, double ang)  //��P ANG ��
    {
        Point v = (*this)-p;
        double c = cos (ang), s = sin (ang);
        return Point (p.x + v.x*c - v.y*s, p.y + v.x*s + v.y*c);
    }
    Point normal () //��λ������
    {
        double l = len ();
        return Point (-y/l, x/l);
    }
};
double cross (Point a, Point b)  //���
{
    return a.x*b.y-a.y*b.x;
}
double dot (Point a, Point b)  //���
{
    return a.x*b.x + a.y*b.y;
}
double dis (Point a, Point b)  //����
{
    Point p = b-a;
    return p.len ();
}
double degree_rad (double ang)  //�ǶȻ�Ϊ����
{
    return ang/180*pi;
}
double rad_degree (double rad)  //���Ȼ��Ƕ�
{
    return rad/pi*180;
}
double rad (Point a, Point b)  //�н�
{
    return fabs (atan2 (fabs (cross (a, b)), dot (a, b)) );
}
bool parallel (Point a, Point b)  //ƽ��
{
    double p = rad (a, b);
    return dcmp (p) == 0 || dcmp (p-pi) == 0;
}
struct Line
{
    Point s, e;//������
    double k;// �Ƕ�[-pi,p]
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
    Line (Point p, double ang)//��бʽ
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
    double length ()  //����
    {
        return dis (s, e);
    }
    void get_angle ()
    {
        k = atan2 (e.y - s.y,e.x - s.x);
    }
    double angle ()  //��б��
    {
        if (dcmp (k) < 0)
            k += pi;
        if (dcmp (k-pi) == 0)
            k -= pi;
        return k;
    }
    Point operator &(const Line &b)const  //ֱ�ߵĽ��㣨��֤����
    {
        Point res = s;
        double t = (cross (s - b.s, b.s - b.e))/cross (s - e, b.s - b.e
                                                      );
        res.x += (e.x - s.x)*t;
        res.y += (e.y - s.y)*t;
        return res;
    }
};
int relation (Point p, Line l)  //���ֱ�ߵĹ�ϵ -1����1��0��
{
    int c = dcmp (cross (p-l.s, l.e-l.s));
    if (c < 0)
        return -1;
    else if (c > 0)
        return 1;
    else
        return 0;
}
bool point_on_halfline (Point p, Line l)  //�жϵ���������
{
    int id = relation (p, l);
    if (id != 3)
        return 0;
    return dcmp (dot (p-l.s, l.e-l.s)) >= 0;
}
bool point_on_seg (Point p, Line l)  //�жϵ����߶���
{
    return dcmp (cross (p-l.s, l.e-l.s)) == 0 &&
           dcmp (dot (p-l.s, p-l.e) <= 0);
}
bool parallel (Line a, Line b)  //ֱ��ƽ��
{
    return parallel (a.e-a.s, b.e-b.s);
}
int seg_cross_seg (Line a, Line v)  //�߶��ཻ 1�淶 2���淶 3���뽻
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
int line_cross_seg (Line a, Line v)  //ֱ�ߺ��߶��ཻ�ж� aֱ��v�߶� 2 �淶 1���淶 3���뽻
{
    int d1 = dcmp (cross (a.e-a.s, v.s-a.s));
    int d2 = dcmp (cross (a.e-a.s, v.e-a.s));
    if ((d1^d2) == -2)
        return 2;
    return (d1 == 0 || d2 == 0);
}
int line_cross_line (Line a, Line v)  //ֱ���ཻ 0ƽ��1�غ�2�ཻ
{
    if (parallel (a, v))
        return relation (a.e, v) == 3;
    return 2;
}
Point line_intersection (Line a, Line v)   //ֱ�߽��㣨�н��㣩
{
    double a1 = cross (v.e-v.s, a.s-v.s);
    double a2 = cross (v.e-v.s, a.e-v.s);
    return Point ((a.s.x*a2-a.e.x*a1)/(a2-a1), (a.s.y*a2-a.e.y*a1)/(a2-
                  a1));
}
int seg_intersectiong (Line a, Line b, Point &p)  //�߶ν��� 0��1�淶2���淶��ȷ��ֻ��һ����
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
double point_to_line (Point p, Line a)  //�㵽ֱ�߾���
{
    return fabs (cross (p-a.s, a.e-a.s) / a.length ());
}
double point_to_seg (Point p, Line a)  //�㵽�߶ξ���
{
    if (dcmp (dot (p-a.s, a.e-a.s)) < 0 || dcmp (dot (p-a.e, a.s-a.e))
            < 0)
        return min (dis (p, a.e), dis (p, a.s));
    return point_to_line (p, a);
}
Point projection (Point p, Line a)  //����ֱ��ͶӰ
{
    return a.s + (((a.e-a.s) * dot (a.e-a.s, p-a.s)) / (a.e-a.s).len2()
                 );
}
Point symmetry (Point p, Line a)  //�����ֱ�߶Գ�
{
    Point q = projection (p, a);
    return Point (2*q.x-p.x, 2*q.y-p.y);
}
//****************Բ
struct Circle
{

    Point p;
    double r;
    Circle () {}
    Circle (Point _p, double _r) : p(_p), r(_r) {}
    Circle (double a, double b, double _r)
    {
        //Բ������ �뾶
        p = Point (a, b);
        r = _r;
    }
    Circle (Point pt1, Point pt2, Point pt3)
    {
        //���� ���߰뾶Ϊ-1
        double x1 = pt1.x, x2 = pt2.x, x3 = pt3.x;
        double y1 = pt1.y, y2 = pt2.y, y3 = pt3.y;
        double a = x1 - x2;
        double b = y1 - y2;
        double c = x1 - x3;
        double d = y1 - y3;
        double e = ((x1 * x1 - x2 * x2) + (y1 * y1 - y2 * y2)) / 2.0;
        double f = ((x1 * x1 - x3 * x3) + (y1 * y1 - y3 * y3)) / 2.0;
        double det = b * c - a * d;
        if (fabs (det) < eps)
        {
            r = -1;
        }
        double x0 = -(d * e - b * f) / det;
        double y0 = -(a * f - c * e) / det;
        r = hypot (x1 - x0, y1 - y0);
        p = Point (x0, y0);
    }
    void input ()
    {
        p.input ();
        scanf ("%lf", &r);
    }
    void output ()
    {
        p.output ();
        printf (" %.2f\n", r);
    }
    bool operator == (const Circle &a) const
    {
        return p == a.p && (dcmp (r-a.r) == 0);
    }
    double area ()//���
    {
        return pi*r*r;
    }
    double circumference ()//�ܳ�
    {
        return 2*pi*r;
    }
    bool operator < (const Circle &a) const
    {
        return p < a.p || (p == a.p && r < a.r);
    }
};
int relation (Point p, Circle a)  //���Բ�Ĺ�ϵ
{
//0:��1:�� 2:��
    double d = dis (p, a.p);
    if (dcmp (d-a.r) == 0)
        return 1;
    return (dcmp (d-a.r) < 0 ? 2 : 0);
}
int relation (Line a, Circle b)  //ֱ�ߺ�Բ
{
//0:����1:���� 2:�ཻ
    double p = point_to_line (b.p, a);
    if (dcmp (p-b.r) == 0)
        return 1;
    return (dcmp (p-b.r) < 0 ? 2 : 0);
}
int relation (Circle a, Circle v)  //��Բ��λ�ù�ϵ
{
//1:�ں�2:���� 3:�ཻ 4:���� 5:����
    double d = dis (a.p, v.p);
    if (dcmp (d-a.r-v.r) > 0)
        return 5;
    if (dcmp (d-a.r-v.r) == 0)
        return 4;
    double l = fabs (a.r-v.r);
    if (dcmp (d-a.r-v.r) < 0 && dcmp (d-l) > 0)
        return 3;
    if (dcmp (d-l) == 0)
        return 2;
    if (dcmp (d-l) < 0)
        return 1;
    return 0;
}
Circle out_circle (Point a, Point b, Point c)  //���������Բ
{
    Line u = Line ((a+b)/2, ((a+b)/2) + (b-a).rotate_left ());
    Line v = Line ((b+c)/2, ((b+c)/2) + (c-b).rotate_left ());
    Point p = line_intersection (u, v);
    double r = dis (p, a);
    return Circle (p, r);
}
Circle in_circle (Point a, Point b, Point c)  //����������Բ
{
    Line u, v;
    double m = atan2 (b.y-a.y, b.x-a.x), n = atan2 (c.y-a.y, c.x-a.x);
    u.s = a;
    u.e = u.s+Point (cos ((n+m)/2), sin ((n+m)/2));
    v.s = b;
    m = atan2 (a.y-b.y, a.x-b.x), n = atan2 (c.y-b.y, c.x-b.x);
    v.e = v.s + Point (cos ((n+m)/2), sin ((n+m)/2));
    Point p = line_intersection (u, v);
    double r = point_to_seg (p, Line (a, b));
    return Circle (p, r);
}
int circle_intersection (Circle a, Circle v, Point &p1, Point &p2)  //����Բ�Ľ���
{

//���ؽ������ ���㱣����Ӧ����
    int rel = relation (a, v);
    if (rel == 1 || rel == 5)
        return 0;
    double d = dis (a.p, v.p);
    double l = (d*d + a.r*a.r - v.r*v.r) / (2*d);
    double h = sqrt (a.r*a.
                     r - l*l);
    Point tmp = a.p + (v.p-a.p).change_len (l);
    p1 = tmp + ((v.p-a.p).rotate_left ().change_len (h));
    p2 = tmp + ((v.p-a.p).rotate_right ().change_len (h));
    if (rel == 2 || rel == 4)
        return 1;
    return 2;
}
int line_cirlce_intersection (Line v, Circle u, Point &p1, Point &p2)
{
//ֱ�ߺ�Բ�Ľ���
//����
    if (!relation (v, u))
        return 0;
    Point a = projection (u.p, v);
    double d = point_to_line (u.p, v);
    d = sqrt (u.r*u.r - d*d);
    if (dcmp (d) == 0)
    {
        p1 = a, p2 = a;
        return 1;
    }
    p1 = a + (v.e-v.s).change_len (d);
    p2 = a - (v.e-v.s).change_len (d);
    return 2;
}
int get_circle (Point a, Point b, double r1, Circle &c1, Circle &c2)
{
//�õ���ab �뾶Ϊr1������Բ ���ظ���
    Circle x (a, r1), y (b, r1);
    int t = circle_intersection (x, y, c1.p, c2.p);
    if (!t)
        return 0;
    c1.r = c2.r = r1;
    return t;
}
int get_circle (Line u, Point q, double r1, Circle &c1, Circle &c2)
{
    //�õ���ֱ��u���� ��q �뾶Ϊr1��Բ
    double d = point_to_line (q, u);
    if (dcmp (d-r1*2) > 0)
        return 0;
    if (dcmp (d) == 0)
    {
        c1.p = q + ((u.e-u.s).rotate_left ().change_len (r1));
        c2.p = q + ((u.e-u.s).rotate_right ().change_len (r1));
        c1.r = c2.r = r1;
        return 2;
    }
    Line u1 = Line (u.s + (u.e-u.s).rotate_left ().change_len (r1), u.e
                    + (u.e-u.s).rotate_left ().change_len (r1));
    Line u2 = Line (u.s + (u.e-u.s).rotate_right ().change_len (r1), u.
                    e + (u.e-u.s).rotate_right ().change_len (r1));
    Circle cc = Circle (q, r1);
    Point p1, p2;
    if (!line_cirlce_intersection (u1, cc, p1, p2))
        line_cirlce_intersection (u2, cc, p1, p2);
    c1 = Circle (p1, r1);
    if (p1 == p2)
    {
        c2 = c1;
        return 1;
    }
    c2 = Circle (p2, r1);
    return 2;
}
int get_circle (Line u, Line v, double r1, Circle &c1, Circle &c2, Circle &c3, Circle &c4)  //��ֱ��u��v���� �뾶Ϊr1
{
    if (parallel (u, v))
        return 0;
    Line u1 = Line (u.s + (u.e-u.s).rotate_left ().change_len (r1), u.e
                    + (u.e-u.s).rotate_left ().change_len (r1));
    Line u2 = Line (u.s + (u.e-u.s).rotate_right ().change_len (r1), u.
                    e + (u.e-u.s).rotate_right ().change_len (r1));
    Line v1 = Line (v.s + (v.e-v.s).rotate_left ().change_len (r1), v.e
                    + (v.e-v.s).rotate_left ().change_len (r1));
    Line v2 = Line (v.s + (v.e-v.s).rotate_right ().change_len (r1), v.
                    e + (v.e-v.s).rotate_right ().change_len (r1));
    c1.r = c2.r = c3.r = c4.r = r1;
    c1.p = line_intersection (u1, v1);
    c2.p = line_intersection (u1, v2);
    c3.p = line_intersection (u2, v1);
    c4.p = line_intersection (u2, v2);
    return 4;
}
int get_circle (Circle cx, Circle cy, double r1, Circle &c1, Circle &c2
               )  //������Բ���� �뾶Ϊr1
{
//��������Բ����
    Circle x (cx.p, r1+cx.r), y (cy.p, r1+cy.r);
    int t = circle_intersection (x, y, c1.p, c2.p);
    if (!t)
        return 0;
    c1.r = c2.r = r1;
    return t;
}
int tan_line (Point q, Circle a, Line &u, Line &v)  //��һ����Բ����
{
    int x = relation (q, a);
    if (x == 2)
        return 0;
    if (x == 1)
    {
        u = Line (q, q + (q-a.p).rotate_left ());
        v = u;
        return 1;
    }
    double d = dis (a.p, q);
    double l = a.r*a.r/d;
    double h = sqrt (a.r*a.r - l*l);
    u = Line (q, a.p + (q-a.p).change_len (l) + (q-a.p).rotate_left ().
              change_len (h));
    v = Line (q, a.p + (q-a.p).change_len (l) + (q-a.p).rotate_right ()
              .change_len (h));
    return 2;
}
double area_circle (Circle a, Circle v)  //��Բ�ཻ���
{
    int rel = relation (a, v);
    if (rel >= 4)
        return 0;
    if (rel <= 2)
        return min (a.area (), v.area ());
    double d = dis (a.p, v.p);
    double hf = (a.r+v.r+d)/2;
    double ss = 2*sqrt (hf*(hf-a.r)*(hf-v.r)*(hf-d));
    double a1 = acos ((a.r*a.r+d*d-v.r*v.r) / (2*a.r*d));
    a1 = a1*a.r*a.r;
    double a2 = acos ((v.r*v.r+d*d-a.r*a.r) / (2*v.r*d));
    a2 = a2*v.r*v.r;
    return a1+a2-ss;
}
double circle_traingle_area (Point a, Point b, Circle c) //Բ�����������
{

//a.output (), b.output (), c.output ();
    Point p = c.p;
    double r = c.r; //cout << cross (p-a, p-b) << endl;
    if (dcmp (cross (p-a, p-b)) == 0)
        return 0;
    Point q[5];
    int len = 0;
    q[len++] = a;
    Line l(a, b);
    Point p1, p2;
    if (line_cirlce_intersection (l, c, q[1], q[2]) == 2)
    {
        if (dcmp (dot (a-q[1], b-q[1])) < 0)
            q[len++] = q[1];
        if (dcmp (dot (a-q[2], b-q[2])) < 0)
            q[len++] = q[2];
    }
    q[len++] = b;
    if (len == 4 && dcmp (dot (q[0]-q[1], q[2]-q[1])) > 0)
        swap (q[1], q[2]);
    double res = 0;
    for (int i = 0; i < len-1; i++)
    {
        if (relation (q[i], c) == 0 || relation (q[i+1], c) == 0)
        {
            double arg = rad (q[i]-p, q[i+1]-p);
            res += r*r*arg/2.0;
        }
        else
        {
            res += fabs (cross (q[i]-p, q[i+1]-p))/2;
        }
    } //cout << res << ".." << endl;
    return res;
}
//******�����
double polygon_area (Point *p, int n)  //������������
{
    double area = 0;
    for (int i = 1; i < n-1; i++)
    {
        area += cross (p[i]-p[0], p[i+1]-p[0]);
    }
    return area/2;
}
bool relation (Point q, Point *p, int n)  //��Ͷ���ι�ϵ����͹����
{
//0:�ⲿ 1:�ڲ� 2:���� 3:����
    for (int i = 0; i < n; i++)
    {
        if (p[i] == q)
            return 3;
    }
    for (int i = 0; i < n; i++)
    {
        if (point_on_seg (q, Line (p[i], p[(i+1)%n])))
            return 2;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        int k = dcmp (cross (q-p[j], p[i]-p[j]));
        int u = dcmp (p[i].y-q.y);
        int v = dcmp (p[j].y-q.y);
        if (k > 0 && u < 0 && v >= 0)
            cnt++;
        if (k < 0 && v < 0 && u >= 0)
            cnt--;
    }
    return cnt != 0;
}
int convex_cut (Line u, Point *p, int n, Point *po)  //ֱ���и��������
{
//�����и������
    int top = 0;
    for (int i = 0; i < n; i++)
    {
        int d1 = dcmp (cross (u.e-u.s, p[i]-u.s));
        int d2 = dcmp (cross (u.e-u.s, p[(i+1)%n]-u.s));
        if (d1 >= 0)
            po[top++] = p[i];
        if (d1*d2 < 0)
            po[top++] = line_intersection (u, Line (p[i], p[
                    (i+1)%n]));
    }
    return top;
}
double convex_circumference (Point *p, int n)  //������ܳ�
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += dis (p[i], p[(i+1)%n]);
    }
    return ans;
}
double area_polygon_circle (Circle c, Point *p, int n)  //����κ�Բ�����
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i+1)%n; //cout << i << " " << j << "//" << endl;
        if (dcmp (cross (p[j]-c.p, p[i]-c.p)) >= 0)
            ans += circle_traingle_area (p[i], p[j], c);
        else
            ans -= circle_traingle_area (p[i], p[j], c);
    }
    return fabs (ans);
}
Point centre_of_gravity (Point *p, int n)  //���������
{
    double sum = 0.0, sumx = 0, sumy = 0;
    Point p1 = p[0], p2 = p[1], p3;
    for (int i = 2; i <= n-1; i++)
    {
        p3 = p[i];
        double area = cross (p2-p1, p3-p2)/2.0;
        sum += area;
        sumx += (p1.x+p2.x+p3.x)*area;
        sumy += (p1.y+p2.y+p3.y)*area;
        p2 = p3;
    }
    return Point (sumx/(3.0*sum), sumy/(3.0*sum));
}
int convex_hull (Point *p, Point *ch, int n)  //��͹��
{
//���е㼯 ͹���㼯 �㼯�ĵ���
    sort (p, p+n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && cross (ch[m-1]-ch[m-2], p[i]-ch[m-1]) < 0)
            {m--;}
        //if(cross (ch[m-1]-ch[m-2], p[i]-ch[m-1])==0) flag++;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--)
    {
        while (m > k && cross (ch[m-1]-ch[m-2], p[i]-ch[m-1]) < 0)
            { m--;}
       // if(cross (ch[m-1]-ch[m-2], p[i]-ch[m-1])==0) flag++;
        ch[m++] = p[i];
    }
    if (n > 1)
        m--;
    return m;
}
double rotate_calipers (Point *p, int m)  //��ת���� ƽ�����ƽ����Զ���
{
//������sqrt
    double ans = 0;
    int cur = 1;
    for (int i = 0; i < m; i++)
    {
        while (cross (p[i]-p[(i+1)%m], p[(cur+1)%m]-p[cur]) < 0)
            cur = (cur+1)%m;
        ans = max (ans, max (dis (p[i], p[cur]), dis (p[(i+1)%m], p[(cur+1)%m])));
    }
    return ans;
}
//�ж�һ�����Ƿ���͹����ε��ڲ����߽߱��� logn
bool Compl_inside_convex(const Point & p,Point *con, int n)
{
    //�� ͹�� �������Ŀ
    if(n<3)
        return false;
    if(cross(p-con[0],con[1]-con[0])>eps)
        return false; //���ڱ߽�Ļ���Ϊ>-eps
    if(cross(p-con[0],con[n-1]-con[0])<-eps)
        return false; //���ڱ߽�Ļ���Ϊ<eps

    int i=2,j=n-1;
    int line=-1;
    while(i<=j)
    {
        int mid=(i+j)>>1;
        if(cross(p-con[0],con[mid]-con[0])>-eps)
        {
            line=mid;
            j=mid-1;
        }
        else
            i=mid+1;
    }
    return cross(p-con[line-1],con[line]-con[line-1])<eps;//���ڱ߽�Ļ���Ϊ<-eps
}
bool get_dir (Point *p, int n)  //�õ�����ε�ʱ��ѭ��
{
//0:˳ʱ�� 1:��ʱ��
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += cross (p[i], p[(i+1)%n]);
    }
    if (dcmp (sum) > 0)
        return 1;
    return 0;
}
double poly_min_seg (Point *coin, int m)
{
//����ε���̳��� ���԰� n^2
    double ans = INF;
    Point *ch;
    int cnt = convex_hull (coin, ch, m);
    for (int i = 0; i < cnt; i++)
    {
        int j = (i+1)%cnt;
        double tmp = 0;
        for (int k = 0; k < cnt; k++)
            if (k != i && k != j)
            {
                tmp = max (tmp, point_to_line (ch[k], Line (ch[i], ch[j])))
                      ;
            }
        ans = min (ans, tmp);
    }
    return ans;
}
double poly_max_seg (Point *hole, int n)
{
//� ���԰� ^3)

    double ans = 0;
    vector <Point> gg;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                Line cur (hole[i], hole[j]);
                gg.clear ();
                for (int x = 0; x < n; x++)
                {
                    int y = (x+1)%n;
                    int in1, in2;
                    in1 = relation (hole[x], cur);
                    in2 = relation (hole[y], cur);
                    if (in1 == 3)
                        gg.push_back (hole[x]);
                    if (in2 == 3)
                        gg.push_back (hole[y]);
                    if (in1 == 3 || in2 == 3)
                    {
                        continue;
                    }
                    int id = line_cross_seg (cur, Line (hole[x], hole[y]));
                    if (id == 2)
                    {
                        Point p = line_intersection (cur, Line (hole[x], hole[y]));
                    }
                }
                sort (gg.begin (), gg.end ());
                int Max = gg.size ();
                double tmp = 0;
                for (int i = 0; i < Max-1; i++)
                {
                    Point p = Point (gg[i].x+gg[i+1].x, gg[i].y+gg[i+1].y)/
                              2;
                    int id = relation (p, hole, n);
                    if (id == 0)
                    {
                        ans = max (ans, tmp);
                        tmp = 0;
                    }
                    else
                    {
                        tmp += dis (gg[i], gg[i+1]);
                    }
                }
                ans = max (ans, tmp);
            }
    }
    return ans;
}
//��ƽ�潻 ֱ�����Ϊ��Ч����
bool HPIcmp (const Line &a, const Line &b)
{
    if (fabs(a.k - b.k) > eps)
        return a.k < b.k;
    return cross (a.s - b.s, b.e - b.s) < 0;
}
Line Q[maxn];
void HPI(Line line[], int n, Point res[], int &resn)
{
//��ƽ������ ��ƽ����� ��ƽ�潻���� ��ƽ�潻�������
    for (int i = 0; i < n; i++)
        line[i].get_angle ();
    int tot = n;
    sort(line,line+n,HPIcmp);
    tot = 1;
    for(int i = 1; i < n; i++)
    {
        if(fabs(line[i].k - line[i-1].k) > eps)
            line[tot++] = line[i];
    }
    int head = 0, tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2; i < tot; i++)
    {
        if (fabs(cross (Q[tail].e-Q[tail].s, Q[tail-1].e-Q[tail-1].s))
                < eps || fabs(cross (Q[head].e-Q[head].s, Q[head+1].e-Q[head+1].s)) < eps)
            return;
        while(head < tail && (cross ((Q[tail]&Q[tail-1])-line[i].s, line[i].e-line[i].s)) > eps)
            tail--;
        while(head < tail && (cross ((Q[head]&Q[head+1]) - line[i].s, line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while(head < tail && (cross ((Q[tail]&Q[tail-1]) - Q[head].s, Q[head].e-Q[head].s)) > eps)
        tail--;
    while(head < tail && (cross ((Q[head]&Q[head-1]) -Q[tail].s, Q[tail].e-Q[tail].e)) > eps)
        head++;
    if(tail <= head + 1)
        return;
    for(int i = head; i < tail; i++)
        res[resn++] = Q[i]&Q[i+1];
    if(head < tail - 1)
        res[resn++] = Q[head]&Q[tail];
}
Point a[1005],b[1005],ha;
int n,t;
int judge(int n)
{
    b[n]=b[0];
    for(int i =0;i<=n;i++)
    {
        Line haa(b[i],b[(i+1)%(n+1)]);
       for(int j =0;j<=n;j++)
       {
           if(j==i||j==(i+1)%(n+1))continue;
           if(point_on_seg(b[j],haa)) return 0;
       }
    }
    return 1;
}
int main()
{
    //ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
            scanf("%d",&n);
            for(int j =0;j<n;j++)
                a[j].input();
             n=convex_hull(a,b,n);
             b[n]=b[0];
            for(int i = 0;i<n;i++)
            {
                Line ha(b[i],b[i+1]);
                for(int j =a[])
            }
    }}

    return 0;
}
