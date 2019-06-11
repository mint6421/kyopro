
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
int a,b,c,d,e;
int ans=0;

main(){
  cin>>n;
  rep(i,n){
    int m;
    cin>>m;
    if(m==4) a++;
    if(m==8) b=min(b+1,a);
    if(m==15) c=min(c+1,b);
    if(m==16) d=min(d+1,c);
    if(m==23) e=min(e+1,d);
    if(m==42) ans=min(ans+1,e);
  }

  cout<<n-6*ans<<endl;
}

