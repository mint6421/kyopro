
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
#define IP pair<int,P>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}

char c[1000][1000];
int d[1000][1000];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int h,w,k;
  cin>>h>>w>>k;
  P s;

  rep(i,h){
    cin>>c[i];
    rep(j,w){
      if(c[i][j]=='S') s=P(i,j);
    }
  }

  
  rep(i,h){
    rep(j,w){
      d[i][j]=INF;
    }
  }

  d[s.F][s.S]=0;
  queue<P> q;
  q.push(s);
  while(q.size()){
    P p=q.front(); q.pop();
    rep(k,4){
      int y=p.F+vy[k],x=p.S+vx[k];
      if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
      if(c[y][x]!='#'&&d[y][x]>d[p.F][p.S]+1){
        d[y][x]=d[p.F][p.S]+1;
        q.push(P(y,x));
      }
    }
  }

  int ans=INF;

  rep(i,h){
    rep(j,w){
      if((i==0||i==h-1||j==0||j==w-1)&&d[i][j]<=k){
        //cout<<d[i][j]<<endl;
        //cout<<i<<j<<endl;
        ans=1;
      }else if(d[i][j]<=k){
        int res=(i+k-1)/k;
        res=min(res,(j+k-1)/k);
        res=min(res,(h-i-1+k-1)/k);
        res=min(res,(w-j-1+k-1)/k);
        ans=min(ans,res+1);
        //cout<<i<<' '<<j<<res<<endl;
      }
    }
  }

  cout<<ans<<endl;


}
