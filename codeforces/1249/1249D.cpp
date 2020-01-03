

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

  int n,k;
  cin>>n>>k;
  vector<PI> v;
  rep(i,n){
    int l,r;
    cin>>l>>r;
    v.PB(PI(P(l,r),i+1));
  }
  sort(all(v));

  vi ans;
  set<P> st;
  int i=0;
  priority_queue<P> q;
  rep(l,210000){
    while(i<n&&v[i].F.F==l){
      P p=P(v[i].F.S,v[i].S);
      st.insert(p);
      q.push(p);
      i++;
    }
    while(st.size()>k){
      P p=q.top(); q.pop();
      if(st.find(p)!=st.end()){
        st.erase(st.find(p));
        ans.PB(p.S);
      }
    }
    while(st.size()&&st.begin()->F==l) st.erase(st.begin());
  }

  cout<<ans.size()<<endl;
  sort(all(ans));
  for(int x:ans){
    cout<<x<<' ';
  }
  cout<<endl;

}
