
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


int n;
int f(vi x,vi y,vi a,vi b){
  int sum=0;
  rep(i,n){
    sum+=(a[x[i]]>b[y[i]]);
  }

  return (sum*2>n);
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n;
  vi a(n),b(n);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>b[i];
  }

  vi c;
  rep(i,n){
    c.PB(i);
  }
  vector<vi> v;
  do{
    v.PB(c);
  }while(next_permutation(all(c)));

  int sum=0,m=0;
  rep(i,v.size()){
    rep(j,v.size()){
      sum+=f(v[i],v[j],a,b);
      m++;
    }
  }

  printf("%.10lf\n",(double)sum/(double)m);

}
