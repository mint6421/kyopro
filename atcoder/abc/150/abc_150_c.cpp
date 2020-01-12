

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

  int n;
  cin>>n;
  vi p(n),q(n);
  rep(i,n){
    cin>>p[i];
  }
  rep(i,n){
    cin>>q[i];
  }

  int a=0,b=0;
  vi v(n);
  rep(i,n){
    v[i]=i+1;
  }
  int cnt=1;
  do{
    bool s=true;
    rep(i,n){
      s&=v[i]==p[i];
    }
    if(s) a=cnt;
    s=true;
    rep(i,n){
      s&=v[i]==q[i];
    }
    if(s) b=cnt;
    cnt++;
  }while(next_permutation(all(v)));

  cout<<abs(a-b)<<endl;



}
