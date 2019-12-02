
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
#define vi vector<int>



main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q,k;
  cin>>q>>k;
  priority_queue<int> q1;
  priority_queue<int,vector<int>,greater<int>> q2;

  while(q--){
    int a;
    cin>>a;
    if(a==1){
      int p;
      cin>>p;
      if(q1.size()<k||q1.top()>p){
        q1.push(p);
        if(q1.size()>k){
          q2.push(q1.top());
          q1.pop();
        }
      }else{
        q2.push(p);
      }
    }else{
      if(q1.size()<k){
        cout<<-1<<endl;
      }else{
        cout<<q1.top()<<endl;
        q1.pop();
        if(!q2.empty()){
          q1.push(q2.top());
          q2.pop();
        }
      }
    }
  }

}


