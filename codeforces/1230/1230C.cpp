

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;
  cin>>n>>m;
  int es[8][8]={};
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a][b]++;
    es[b][a]++;
  }

  if(n<7){
    cout<<m<<endl;
    return 0;
  }

  int mn=inf;
  rep(i,n){
    FOR(j,i+1,n){
      int t=0;
      rep(k,n){
        if(es[i][k]&&es[k][j]){
          t++;
        }
      }
      mn=min(t,mn);
    }
  }

  cout<<m-mn<<endl;


}
