
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


int n,k;
int x[110000];
int ans;


main(){
  cin>>n>>k;
  rep(i,k){
    cin>>x[i];
  }

  int ans=n+2*(n-1);

  bool b[110000]={};
  map<P,bool> mp;

  rep(i,k){
    if(!b[x[i]]){
      ans--;
      b[x[i]]=true;
    }
    if(x[i]-1>0&&b[x[i]-1]&&!mp[P(x[i],x[i]-1)]){
      ans--;
      mp[P(x[i],x[i]-1)]=true;
    }
    if(x[i]+1<n+1&&b[x[i]+1]&&!mp[P(x[i],x[i]+1)]){
      ans--;
      mp[P(x[i],x[i]+1)]=true;
    }

//    cout<<ans<<endl;
  }

  cout<<ans<<endl;
}
