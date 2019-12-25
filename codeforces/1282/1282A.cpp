

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

  int q;
  cin>>q;
  while(q--){
    int a,b,c,r;
    cin>>a>>b>>c>>r;
    if(a>b) swap(a,b);
    if(a<=c-r&&c+r<=b){
      cout<<b-a-2*r<<endl;
    }else if(c+r<=a||b<=c-r){
      cout<<b-a<<endl;
    }else if(c-r<=a&&b<=c+r){
      cout<<0<<endl;
    }else if(c-r<=b&&b<=c+r){
      cout<<c-r-a<<endl;
    }else {
      cout<<b-(c+r)<<endl;
    }
  }

}
