
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
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
#define PP pair<P,int>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x,y;
  cin>>x>>y;
  set<P> s;
  queue<PP> q;
  q.push(PP(P(0,0),0));


  while(!q.empty()){
    int dx=q.front().F.F,dy=q.front().F.S;
    int k=q.front().S;
    q.pop();
    if(k>=3) continue;
    s.insert(P(dx,dy));    
    FOR(i,-2,3){
      FOR(j,-2,3){
        if(abs(i*j)!=2) continue;
        s.insert(P(dx+i,dy+j));
        q.push(PP(P(dx+i,dy+j),k+1));
        //cout<<dx+i<<' '<<dy+j<<endl;
      }
    }
  }



if(s.find(P(x,y))!=s.end()){
  cout<<"YES"<<endl;
}else{
  cout<<"NO"<<endl;
}




}
