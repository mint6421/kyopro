

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

bool f(int t,vi &a,int m){
  int cnt=0;
  int n=a.size();
  rep(i,n){
    int it=lower_bound(all(a),t-a[i])-a.begin();
    cnt+=n-it;
  }

  return cnt>=m;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;
  cin>>n>>m;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(all(a));
  
  int l=0,r=INF;
  while(r-l>1){
    int mi=(r+l)/2;
    if(f(mi,a,m)) l=mi;
    else r=mi;
  }


  vi sum(n+1,0);
  rep(i,n){
    sum[i+1]=sum[i]+a[i];
  }

  int ans=0;
  int e=0;
  rep(i,n){
    int it=lower_bound(all(a),l-a[i])-a.begin();
    ans+=sum[n]-sum[it];
    ans+=(n-it)*a[i];
    e+=(n-it);
  }

  ans-=(e-m)*l;
  cout<<ans<<endl;


}
