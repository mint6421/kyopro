
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

int n,s;
vector<int> p;
vector<vi> vec[2];
map<int,vector<vi>> mp[2];


void dfs(int t,vi v,int l,int m){
  if(l==m){
    mp[m/n][t].PB(v);
    return;
  }

  dfs(t,v,l+1,m);
  v.PB(l+1);
  dfs(t+p[l],v,l+1,m);


}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>s;
  p=vi(n);

  rep(i,n){
    cin>>p[i];
  }

  dfs(0,vi(),0,n/2+1);
  dfs(0,vi(),n/2+1,n);

  vector<vi> ans;

  for(auto m:mp[0]){
    int t=s-m.F;
    if(mp[1][t].size()){
      for(vi v1:m.S){
        for(vi v2:mp[1][t]){
          vi v;
          for(int i:v1) v.PB(i);
          for(int i:v2) v.PB(i);
          ans.PB(v);
        }
      }
    }
  }

  sort(all(ans));

  for(vi v:ans){
    for(int i:v) cout<<i<<' ';
    cout<<endl;
  }

}
