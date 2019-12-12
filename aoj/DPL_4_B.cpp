

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k,l,r;
  cin>>n>>k>>l>>r;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }

  vector<vi> v1(n/2+1);
  vector<vi> v2(n/2+n%2+1);

  rep(bit,1<<(n/2)){
    int cnt=0;
    int s=0;
    rep(i,n/2){
      if(bit&(1<<i)){
        cnt++;
        s+=a[i];
      }
    }
    v1[cnt].PB(s);
  }

  rep(bit,1<<(n/2+n%2)){
    int cnt=0;
    int s=0;
    rep(i,n/2+n%2){
      if(bit&(1<<i)){
        cnt++;
        s+=a[i+n/2];
      }
    }
    v2[cnt].PB(s);
  }

  rep(i,n/2+1){
    sort(all(v1[i]));
  }
  rep(i,n/2+n%2+1){
    sort(all(v2[i]));
  }

  int ans=0;
  rep(i,n/2+1){
    int j=k-i;
    if(j>=v2.size()) continue;
    for(int c:v1[i]){
      //cout<<c<<' '<<j<<endl;
      ans+=upper_bound(all(v2[j]),r-c)-lower_bound(all(v2[j]),l-c);
    }
  }

  cout<<ans<<endl;

}
