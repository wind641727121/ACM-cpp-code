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
#include<stack>
using namespace std;
#define bug1(g) cout<<"test: "<<g<<endl
#define bug2(g,i) cout<<"test: "<<g<<" "<<i<<endl
#define bug3(g,i,k) cout<<"test: "<<g<<" "<<i<<" "<<k<<endl

stack<char>st ;
stack<int>num;
int main(){
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;s[i];i++){
	   if(st.empty()){
	   	  st.push(s[i]);
	   	  num.push(i+1);
			 i++;
	   }
		char temp=st.top();
		if(temp==')'){
			st.push(s[i]);
		}
	    else if(temp=='('&&s[i]==')'){
	    	st.pop();
		}
		else {
			st.push(s[i]);
		}
	}
	if(!st.empty())
    {
        string a="";
            cout<<"No"<<endl;
         while(!st.empty()){
            a=st.top()+a;
                st.pop();
            }
            cout<<a<<endl;
        }
	else    cout<<"Yes"<<endl;



	return 0;
}
