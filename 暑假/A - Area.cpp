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
    P[n]=P[0];
    for(int i =0;i<n;i++)
    {
        sum+=Cross(P[i]-ha,P[i+1]-ha);
    }
    return max(sum/2,-sum/2);
}
int seg(Point a,Point b,Point c,Point d)
{
    int d1=dcmp(Cross(b-a,c-a));
    int d2=dcmp(Cross(b-a,d-a));
    int d3=dcmp(Cross(d-c,a-c));
    int d4=dcmp(Cross(d-c,b-c));
    if((d1^d2) == -2&&(d3^d4)==-2) return 2;
    return(d1==0&&dcmp(Dot(c-a,c-b))<=0) ||
          (d2==0&&dcmp(Dot(d-a,d-b))<=0) ||
          (d3==0&&dcmp(Dot(a-c,a-d))<=0) ||
          (d4==0&&dcmp(Dot(b-c,b-d))<=0);
}
int main(){
    int n;
    int k =0;
    while(~scanf("%d",&n)&&n){
            cout<<"Figure "<<++k<<": ";
        for(int i=0;i<n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
        if(n<=2) {cout<<"Impossible"<<endl;continue;}
        int flag=1;
        for(int i =0;i<n-1&&flag;i++)
            for(int j =i+2;j<n-1&&flag;j++)
                if(seg(P[i],P[i+1],P[j],P[j+1])!=0) flag=0;
     for(int i =1;i<n-2&&flag;i++)
            if(seg(P[n-1],P[0],P[i],P[i+1])!=0) flag=0;
        if(flag&&area(n)!=0)
           printf("%.2f\n",area(n));
        else
            {cout<<"Impossible"<<endl;continue;}
    }
    return 0;
}
