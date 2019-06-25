
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


int ans=INF;
int n,k;
int a[100];

void dfs(vector<int> v,int i){
  if(v.size()==k){
    int sum=0;
    rep(i,v.size()){
      sum+=v[i];
    }
    int res=0;
    while(sum){
      int r=sum%10;
      res+=r%5+r/5;
      sum/=10;
    }
    ans=min(ans,res);
    return;
  }

  if(i==n) return;

  dfs(v,i+1);

  v.PB(a[i]);

  dfs(v,i+1);
}



main(){
  cin>>n>>k;
  rep(i,n){
    cin>>a[i];
  }

  dfs(vector<int>(),0);

  cout<<ans<<endl;
}
