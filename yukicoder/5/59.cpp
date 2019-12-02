
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




struct BIT{
  vector<int> bit;
  int n;

  BIT(int m){
    n = m;
    bit.assign(2*n,0);
  }

  int sum(int i){
    int s = 0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }
  void add(int i,int x){
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }
};

int c[1100000];
BIT bit(1100000);

main(){
  int n,k;
  cin>>n>>k;
  int ans=0;

  rep(i,n){
    int w;
    cin>>w;
    if(w<0){
      w=-w;
      if(c[w]==0) continue;
      c[w]--;
      bit.add(w,-1);
      ans--;
    }else{
      if(ans-bit.sum(w-1)>=k) continue;
      c[w]++;
      bit.add(w,1);
      ans++;
    }
  }

  cout<<ans<<endl;


}
