
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

int f(int k){
  
  for(int i=2;i*i<=k;i++){
    if(k%i==0) return i;
  }
  return k;
}

main(){
  int n;
  int m=1;
  cin>>n;
  vector<int> v(n+1);

  FOR(i,2,n+1){
    int r=f(i);
    if(r==i) v[i]=m++;
    else v[i]=v[r];
    cout<<v[i]<<' ';
  }

  cout<<endl;
}
