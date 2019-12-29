

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
  set<int> st;
  set<int> t;
  rep(i,n){
    int x;
    cin>>x;
    st.insert(x);
    t.insert(x);
  }

  set<int> ans;
  int d=1;
  int res=0;
  while(ans.size()<m){
    set<int> s;
    for(int x:st){
      bool flag=false;
      if(ans.find(x+d)==ans.end()&&t.find(x+d)==t.end()){
        ans.insert(x+d);
        res+=d;
        flag=true;
      }
      if(ans.size()==m) break;
      if(ans.find(x-d)==ans.end()&&t.find(x-d)==t.end()){
        ans.insert(x-d);
        res+=d;
        flag=true;
      }
      if(ans.size()==m) break;
      if(flag) s.insert(x);
    }
    d++;
    st=s;
  }

  cout<<res<<endl;
  for(int x:ans){
    cout<<x<<' ';
  }
  cout<<endl;


}
