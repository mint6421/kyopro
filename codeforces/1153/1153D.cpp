
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




int a[400000],b[400000];
bool c[400000];
vector<vector<int>> es;


int dfs(int k){
  c[k]=true;
  int sum=0,m=inf;
  bool flag=false;
  
  for(auto e:es[k]){
    if(c[e]) continue;
    flag=true;
    int t = dfs(e);
    sum+=t;
    m=min(m,t);
  }

  if(!flag) return 1;
  if(a[k]==1) return m;

  return sum;
}


main(){
  int n;
  cin>>n;

  rep(i,n){
    cin>>a[i];
  }
  es = vector<vector<int>>(n);

  rep(i,n-1){
    cin>>b[i];
    b[i]--;
    es[b[i]].PB(i+1);
  }

  bool flag[400000]={};
  rep(i,n-1){
    flag[b[i]]=true;
  }
  int res=0;
  rep(i,n){
    res+=(!flag[i]);
  }

  cout<<res+1-dfs(0)<<endl;
}

