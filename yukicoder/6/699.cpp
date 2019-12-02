

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}

int n;
vi a;
int ans=0;

void f(vi b,bool use[]){
  if(b.size()==n){
    /*
    rep(i,n){
      cout<<b[i]<<' ';
    }
    cout<<endl;
    */
    int res=0;
    for(int i=0;i<n;i+=2){
      res^=(a[b[i]]+a[b[i+1]]);
    }
    ans=max(ans,res);
    return;
  }

  int k=-1;
  rep(i,n){
    if(use[i]) continue;
    k=i;
    break;
  }
  use[k]=true;
  b.PB(k);

  FOR(i,k+1,n){
    if(!use[i]){
      b.PB(i);
      use[i]=true;
      f(b,use);
      use[i]=false;
      b.erase(b.end()-1);
    }
  }

  b.erase(b.end()-1);
  use[k]=false;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n;
  a=vi(n);
  rep(i,n){
    cin>>a[i];
  }

  bool use[n]={};

  f(vi(),use);

  cout<<ans<<endl;

}
