
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

map<int,bool> mp;

void f(int s,int m,int l,int n,int k){
  if(m==n+1){
    mp[s]=true;
    //cout<<s<<endl;
    return;
  }

  if(l<k){
    f(s-m,m+1,l+1,n,k);
  }

  f(s+m,m+1,l,n,k);

}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k;
  cin>>n>>k;
  //f(0,1,0,n,k);

  //cout<<mp.size()<<endl;

  cout<<1+k*(2*n-k+1)/2<<endl;

}
