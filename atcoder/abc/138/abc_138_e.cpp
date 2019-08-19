
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
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
#define vi vector<int>



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> alp[30];

  string s,t;
  cin>>s>>t;

  rep(i,s.size()){
    alp[s[i]-'a'].PB(i+1);
  }

  int st=0,n=(int)s.size();
  int res=0;
  rep(i,t.size()){
    int k=t[i]-'a';
    if(alp[k].empty()){
      cout<<-1<<endl;
      return 0;
    }

    auto it=upper_bound(all(alp[k]),res);
    if(it==alp[k].end()){
      st++;
      it=upper_bound(all(alp[k]),0);
    }
    res=*it;
    //cout<<res<<endl;
  }


  cout<<st*n+res<<endl;


}
