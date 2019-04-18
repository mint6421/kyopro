

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


int b[3];

int f(int o,int c,int d,int e,int f,int g,int h){
  int a[3];
  rep(i,3){
    a[i]=b[i];
  }
  a[o]--;
  if(a[o]<0) return 0;
  a[c]--;
  if(a[c]<0) return 1;
  a[d]--;
  if(a[d]<0) return 2;
  a[e]--;
  if(a[e]<0) return 3;
  a[f]--;
  if(a[f]<0) return 4;
  a[g]--;
  if(a[g]<0) return 5;
  a[h]--;
  if(a[h]<0) return 6;

  
  return 7;
}



int main(){
  cin>>b[0]>>b[1]>>b[2];

  int res=min(b[0]/3,min(b[1]/2,b[2]/2));

  b[0]-=res*3;
  b[1]-=res*2;
  b[2]-=res*2;
 

  int ans=max(f(0,1,2,0,2,1,0),f(1,2,0,2,1,0,0));
  ans=max(ans,f(2,0,2,1,0,0,1));
  ans=max(ans,f(0,2,1,0,0,1,2));
  ans=max(ans,f(2,1,0,0,1,2,0));
  ans=max(ans,f(1,0,0,1,2,0,2));
  ans=max(ans,f(0,0,1,2,0,2,1));

  cout<<res*7+ans<<endl;
}
