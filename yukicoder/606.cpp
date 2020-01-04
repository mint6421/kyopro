

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

  int n,k,q;
  cin>>n>>k>>q;
  vi cnt(k,0);
  set<int> c,r;

  vector<char> a(q);
  vi b(q),s(q);
  rep(i,q){
    cin>>a[i]>>b[i]>>s[i];
    b[i]--;s[i]--;
  }

  rrep(i,q-1){
    if(a[i]=='C'){
      if(c.count(b[i])) continue;
      cnt[s[i]]+=n-r.size();
      c.insert(b[i]);
    }else{
      if(r.count(b[i])) continue;
      cnt[s[i]]+=n-c.size();
      r.insert(b[i]);
    }
  }

  int t=n*n;

  for(int x:cnt){
    t-=x;
  }

  cnt[0]+=t;

  for(int x:cnt){
    cout<<x<<endl;
  }

}
