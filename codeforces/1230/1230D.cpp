

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
  vi a(n),b(n);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>b[i];
  }

  int ans=0;
  set<int> st;
  rep(i,n){
    if(st.find(i)!=st.end()) continue;
    set<int> s;
    FOR(j,i,n){
      if(a[i]==a[j]){
        s.insert(j);
      }
    }
    if(s.size()==1) continue;
    rep(j,n){
      if((a[i]|a[j])==a[i]){
        s.insert(j);
      }
    }
    for(int x:s){
      st.insert(x);
    }

  }

  for(int x:st){
    ans+=b[x];
  }

  cout<<ans<<endl;


}
