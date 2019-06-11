
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


int n,q;
multiset<int> s;

main(){
  cin>>n>>q;

  rep(i,n){
    int a;
    cin>>a;
    s.insert(a);
  }

  while(q--){
    int a,b,x;
    cin>>a>>b>>x;
    auto l=s.lower_bound(a);
    auto r=s.upper_bound(b);
    int res=0;
    int c=0;
    for(auto i=l;i!=r;i++){
      res^=*i;
      c++;
    }

    s.erase(l,r);
    if(c&1) s.insert(x);
    cout<<res<<endl;
  }

}
