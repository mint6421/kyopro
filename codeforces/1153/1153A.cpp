

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

int n,t;
int a[110],b[110];

int f(int x,int y){
  int res=x;
  while(res<t){
    res+=y;
  }

  return res;
}

int main(){
  cin>>n>>t;
  rep(i,n){
    cin>>a[i]>>b[i];
    
  }

  vector<P> v;
  rep(i,n){
      v.PB(P(f(a[i],b[i]),i));   
 
  }

  sort(all(v));
  cout<<v[0].S+1<<endl;
}
