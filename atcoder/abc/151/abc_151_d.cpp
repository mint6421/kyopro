
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}

int h,w;
char s[30][30];
int d[30][30];

int f(int y,int x){
  rep(i,h+1){
    rep(j,w+1){
      d[i][j]=inf;
    }
  }

  d[y][x]=0;
  queue<P> q;
  q.push(P(x,y));
  while(q.size()){
    P p=q.front(); q.pop();
    rep(k,4){
      int i=p.S+vy[k];
      int j=p.F+vx[k];
      if(!(0<=i&&i<h&&0<=j&&j<w)) continue;
      if(s[i][j]=='#') continue;
      if(d[p.S][p.F]+1<d[i][j]){
        d[i][j]=d[p.S][p.F]+1;
        q.push(P(j,i));
      }
    }
  }

  int res=0;
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='#') continue;
      res=max(res,d[i][j]);
    }
  }

  return res;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>h>>w;
  rep(i,h){
    cin>>s[i];
  }

  int ans=0;
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='#') continue;
      ans=max(ans,f(i,j));
    }
  }

  cout<<ans<<endl;


}

