
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

void bfs(vi s,vi t,vi &ans,int n,vector<vi> es){
  vi d(n,inf);
  queue<int> q;
  for(auto x:s){
    d[x]=0;
    q.push(x);
  }

  while(q.size()){
    int p=q.front(); q.pop();
    for(int x:es[p]){
      if(d[x]==inf){
        d[x]=d[p]+1;
        q.push(x);
      }
    }
  }

  for(int x:t){
    ans[x]=min(ans[x],d[x]);
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi odd,even;
  vector<vi> es(n);
  rep(i,n){
    int a;
    cin>>a;
    int l=i-a;
    int r=i+a;
    if(l>=0) es[l].PB(i);
    if(r<n) es[r].PB(i);
    if(a%2) odd.PB(i);
    else even.PB(i);
  }

  vi ans(n,inf);

  bfs(odd,even,ans,n,es);
  bfs(even,odd,ans,n,es);

  rep(i,n){
    cout<<(ans[i]==inf?-1:ans[i])<<' ';
  }
  cout<<endl;


}
