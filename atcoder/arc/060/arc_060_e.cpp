
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

int n,l,q;
vi a;
map<int,int> mp[110000];


int dir(int x,int y){
  if(x==y) return 0;
  if(mp[x][y]) return mp[x][y];

  int r=upper_bound(all(a),a[x]+l)-a.begin();
  r--;
  r=min(r,y);
  int res=1+dir(r,y);
  //cout<<x<<' '<<r<<endl;
  return mp[x][y]=1+dir(r,y);

}
  

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  cin>>n;
  a=vi(n);
  rep(i,n){
    cin>>a[i];
  }
  
  cin>>l>>q;
  
  
  while(q--){
    int x,y;
    cin>>x>>y;
    x--;y--;
    if(x>y) swap(x,y);
    cout<<dir(x,y)<<endl;
  }


}
