#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10005;
const double esp=1e-10;
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x;y=_y;
    }
}P[maxn],Convexhull[maxn],ha(0,0);
typedef Point Vector;
Vector operator + (Vector A,Vector B){
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Vector A,Vector B){
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,double d){
    return Vector(A.x*d,A.y*d);
}
Vector operator / (Vector A,double d){
    return Vector(A.x/d,A.y/d);
}
double Dot(Vector A,Vector B){
    return A.x*B.x+A.y*B.y;
}
double Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}
double Length(Vector A){
    return sqrt(Dot(A,A));
}
int dcmp(double x){
    return fabs(x)<esp?0:x<0?-1:1;
}
bool operator <(Point p1,Point p2){
    return dcmp(p1.x-p2.x)<0||(dcmp(p1.x-p2.x)==0&&dcmp(p1.y-p2.y)<0);
}
int Andrew(int n){      //Assume n>2
    sort(P,P+n);
    int top=0;
    for(int i=0;i<n;i++){
        while(top>1&&dcmp(Cross(P[i]-Convexhull[top-2],Convexhull[top-1]-Convexhull[top-2]))>=0)top--;
        Convexhull[top++]=P[i];
    }
    int k=top;
    for(int i=n-2;i>=0;i--){
        while(top>k&&dcmp(Cross(P[i]-Convexhull[top-2],Convexhull[top-1]-Convexhull[top-2]))>=0)top--;
        Convexhull[top++]=P[i];
    }
    return top-1;
}
double area(int n)
{
    double sum =0;
    Convexhull[n]=Convexhull[0];
    for(int i =0;i<n;i++)
    {
        sum+=Cross(Convexhull[i]-ha,Convexhull[i+1]-ha);
    }
    return max(sum/2,-sum/2);
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
        int cnt=Andrew(n);
        double ans=0;
        printf("%d\n",(int)(area(cnt)/50));
    }
    return 0;
}
