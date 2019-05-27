
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

bool s[110][110];
int p[110];

int ans=0;
int n,m;

void f(int k,bool b[]){
  if(k==n){
    int res=0;
    rep(i,m){
      int flag=0;
      rep(j,n){
        if(b[j]&&s[i][j]) flag++;
      }
      if(flag%2==p[i])res++;
    }
   if(res==m) ans++;
   return;
  } 

  b[k]=true;
  f(k+1,b);
  b[k]=false;
  f(k+1,b);
}


main(){

  cin>>n>>m;
  rep(i,m){
    int k;
    cin>>k;
    rep(j,k){
      int a;
      cin>>a;
      a--;
      s[i][a]=true;
    }
  }
  rep(i,m){
    cin>>p[i];
  }

  bool b[110]={};
  f(0,b);

  cout<<ans<<endl;
}
