#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10005;
int m;
const double esp=1e-10,eps=1e-7;
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
} P[maxn],Convexhull[maxn],ha(0,0);
typedef Point Vector;
Vector operator + (Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Vector A,Vector B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,double d)
{
    return Vector(A.x*d,A.y*d);
}
Vector operator / (Vector A,double d)
{
    return Vector(A.x/d,A.y/d);
}
double Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
double Length(Vector A)
{
    return sqrt(Dot(A,A));
}
int dcmp(double x)
{
    return fabs(x)<esp?0:x<0?-1:1;
}
bool operator <(Point p1,Point p2)
{
    return dcmp(p1.x-p2.x)<0||(dcmp(p1.x-p2.x)==0&&dcmp(p1.y-p2.y)<0);
}
int Andrew(int n)       //Assume n>2
{
    sort(P,P+n);
    int top=0;
    for(int i=0; i<n; i++)
    {
        while(top>1&&dcmp(Cross(P[i]-Convexhull[top-2],Convexhull[top-1]-Convexhull[top-2]))>=0)
            top--;
        Convexhull[top++]=P[i];
    }
    int k=top;
    for(int i=n-2; i>=0; i--)
    {
        while(top>k&&dcmp(Cross(P[i]-Convexhull[top-2],Convexhull[top-1]-Convexhull[top-2]))>=0)
            top--;
        Convexhull[top++]=P[i];
    }
    return top-1;
}
bool check(double a,double b,double c)//检查是否钝角三角形
{
	if(a*a+b*b<c*c || a*a+c*c<b*b || b*b+c*c<a*a)
		return 1;//是钝角三角形
	return 0;
}
double lenth(Point a,Point b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double R(Point p1,Point p2,Point p3)//计算三角形外接圆半径
{
	double a=lenth(p1,p2);
	double b=lenth(p2,p3);
	double c=lenth(p1,p3);
	if(check(a,b,c))//是钝角三角形
		return max(a,max(b,c))/2.0;
	double s=fabs(Cross(p2-p1,p3-p1))/2.0;
	return a*b*c/(4.0*s);
}
double area(int n)
{
    double sum =0;
    Convexhull[n]=Convexhull[0];
    for(int i =0;i<n;i++)
    {
        sum+=Length(Convexhull[i+1]-Convexhull[i]);
    }
    return sum+3.1415926*2*m;
}
int main()
{
    int n;
    while(~scanf("%d %d",&n,&m))
    {
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&P[i].x,&P[i].y);
        int cnt=Andrew(n);
        double ans=0;
        printf("%.0f\n",area(cnt));
    }
    return 0;
}
