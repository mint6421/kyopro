
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
#define vi vector<int>


int n,m;

int f(bool b[]){
  int a[100]={};
  a[1]=1;
  a[2]=1;

  FOR(i,3,n+1){
    a[i]=a[i-1]+a[i-2];
    if(b[i]) a[i]--;
  }

  return a[n];
}

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>m;

  bool b[100]={};
  FOR(i,2,n+1){
    b[i]=true;
    int res=f(b);
    if(res==m){
      int ans=0;
      FOR(j,3,n+1){
        ans+=b[j];
      }
      cout<<ans<<endl;
      return 0;
    }
    if(res<m) b[i]=false;
  }

  cout<<-1<<endl;

}


