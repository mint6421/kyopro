
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


ll n,m;
ll t[300000];
int l[300000],r[300000];
int nl[300000],nr[300000];
bool b[300000];

int main(){
  cin>>n>>m;
  rep(i,m){
    cin>>t[i]>>l[i]>>r[i];
  }  

  rep(i,n+1){
    nr[i]=i+1;
  }

  ll ans=0;

  rrep(i,m){
    ll sum=0; 
    int j=l[i];
    int lr=j;
    while(j<=r[i]){
      if(!b[j]){
        b[j]=true;
        sum++;
      }
      int ji=j;
      j=nr[j];
      nr[ji]=r[i]+1;
    }
    ans+=sum*t[i];
  }

  cout<<ans<<endl;

}
