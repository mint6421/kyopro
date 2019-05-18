
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int n,a,b,s;

void dfs(int x,int y,int ban){
  if(__builtin_popcount(ban^s)==1){
    cout<<y<<' '<<(x^y)<<" ";
    return;
  }

 
  rep(i,n){

    if(((~ban>>i)&1)&&((x>>i)&1)){
    
      rep(j,n){
        if(((~ban>>j)&1)&&i!=j){
          dfs(1<<j,y,ban|1<<i);
          dfs(x^(1<<i)^(1<<j),y^(1<<i)^(1<<j),ban|1<<i);
          return;
        }
      }
    }
  }
}



main(){
  
  cin>>n>>a>>b;
  s = (1<<n)-1;
  if(__builtin_popcount(a^b)%2){
    cout<<"YES"<<endl;
    dfs(a^b,a,0);
    cout<<endl;
  }else{
    cout<<"NO"<<endl;
  }

}
