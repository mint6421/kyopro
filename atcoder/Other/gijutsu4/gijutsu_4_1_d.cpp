
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



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  vi v(n);
  bool f=true;
  rep(i,n){
    cin>>v[i];
    if(v[0]!=v[i]) f=false;
  }

  if(f){
    cout<<0<<endl;
    return 0;
  }

  int ans=1;
  int i=1;
  int j=0;
  while(v[j]==v[j+1]) j++;
  bool flag=(v[j]<v[j+1]);
  while(i<n){
    int j=i;
    if(flag){
      while(j<n&&v[j-1]<=v[j]) j++;
      ans++;
      flag=false;
    }else{
      while(j<n&&v[j-1]>=v[j]) j++;
      ans++;
      flag=true;
    }
    //cout<<i<<j<<endl;
    i=j;
  }

  cout<<ans<<endl;
}

