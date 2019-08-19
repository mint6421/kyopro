
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

int ans[201000];
int c[201000];
vector<vi> v;

void dfs(int k,int s){
  s+=c[k];
  ans[k]=s;
  
  for(auto e:v[k]){
    dfs(e,s);
  }

}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,q;
  cin>>n>>q;
  v = vector<vi>(n);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    v[a].PB(b);
  }


  rep(i,q){
    int p,x;
    cin>>p>>x;
    p--;
    c[p]+=x;
  }

  dfs(0,0);

  rep(i,n){
    if(i) cout<<' ';
    cout<<ans[i];
  }
  cout<<endl;

}
