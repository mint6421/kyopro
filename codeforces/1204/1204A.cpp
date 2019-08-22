
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



bool f(string s,string t){
  if(s.size()>t.size()) return true;
  if(s.size()<t.size()) return false;

  rep(i,s.size()){
    if(s[i]>t[i]) return true;
    if(s[i]<t[i]) return false;
  }

  return false;
}

string pow(string s){
  return s+"00";
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin>>s;
  string t="1";

  int ans=0;
  while(f(s,t)){
    ans++;
    t=pow(t);
  }
  cout<<ans<<endl;

}
