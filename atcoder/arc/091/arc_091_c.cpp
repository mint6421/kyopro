
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


vi f(int N,int A,int B){
  vi res;
  rrep(i,B-1) res.PB(i);

  if(A==1) return res;

  int rem=N-B;
  int p=rem/(A-1);
  int r=rem%(A-1);
  int b=r;
  int c=A-1-r;

  rep(i,b){
    int size=res.size();
    rep(j,p+1){
      res.PB(size+p-j);
    }
  }

  rep(i,c){
    int size=res.size();
    rep(j,p){
      res.PB(size+p-1-j);
    }
  }

  return res;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,a,b;
  cin>>n>>a>>b;

  if(a+b>n+1||a*b<n){
    cout<<-1<<endl;
    return 0;
  }

  vi res = f(n,a,b);

  rep(i,res.size()){
    cout<<res[i]+1<<' ';
  }
  cout<<endl;



}
