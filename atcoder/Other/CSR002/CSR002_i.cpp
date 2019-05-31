
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
int ans=-1;
P v[210000];

void f(int k){
  int x=v[k].F,y=v[k].S;
  rep(i,n){
    if(i==k) continue;
    int a=v[i].F,b=v[i].S;
    int s=(x+b-1)/b;
    int t=(y+a-1)/y;
    if(s<=t) return;
  }
  ans=k+1;
}


main(){
  
  cin>>n;
  rep(i,n){
    cin>>v[i].F>>v[i].S;
  }

  rep(i,n){
    f(i);
  }

  cout<<ans<<endl;
}
