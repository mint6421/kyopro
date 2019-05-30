
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


main(){
  int q;
  cin>>q;
  priority_queue<int> q1;
  priority_queue<int,vector<int>,greater<int>> q2;
  int q1sum=0,q2sum=0;
  int sum=0;

  while(q--){
    int a;
    cin>>a;
    if(a==1){
      int b,c;
      cin>>b>>c;
      sum+=c;
      if(q1.empty()){
        q1.push(b);
        q1sum+=b;
      }else if(q1.top()>b){
        q1.push(b);
        q1sum+=b;
        if(q1.size()-q2.size()>1){
          q2.push(q1.top());
          q2sum+=q1.top();
          q1sum-=q1.top();
          q1.pop();
        }
      }else if(q2.empty()||q2.top()<b){
        q2.push(b);
        q2sum+=b;
        if(q2.size()-q1.size()>0){
          q1.push(q2.top());
          q1sum+=q2.top();
          q2sum-=q2.top();
          q2.pop();
        }
      }else{
        if(q1.size()-q2.size()>0){
          q2.push(b);
          q2sum+=b;
        }else{
          q1.push(b);
          q1sum+=b;
        }
      }
    }else{
      int res=sum;
      res+=q1.size()*q1.top()-q1sum;
      res+=q2sum-q1.top()*q2.size();
//      cout<<q1sum<<' '<<q2sum<<endl;
      cout<<q1.top()<<' '<<res<<endl;
    }
//    cout<<q1.size()<<' '<<q2.size()<<' '<<q1sum<<' '<<q2sum<<endl;
  }
}
