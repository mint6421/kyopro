
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


int n;
int ans=INF;
vector<int> a;
vector<int> b;

void f(int m){

  priority_queue<P,vector<P>,greater<P>> q;
  rep(i,n){
    q.push(P(a[i],0));
  }

  rep(i,n){
    int k=(i+m)%n;
    P p=q.top(); q.pop(); 
    q.push(P(p.F+b[k]/2,p.S+1));
  }

  int res=-1;
  while(!q.empty()){
    P p=q.top(); q.pop();
    res=max(res,p.S);
  }

  ans=min(ans,res);
}


main(){
  cin>>n;
  a.resize(n);
  b.resize(n);

  rep(i,n){
    cin>>a[i];
  }

  rep(i,n){
    cin>>b[i];
  }

  rep(i,n){
    f(i);
  }


  cout<<ans<<endl;
}
