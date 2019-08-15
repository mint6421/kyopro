
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

map<string,bool> mp;

void f(string s,string t){
  
  //cout<<s<<' '<<t<<endl;
  if(t.empty()){
    mp[s]=true;
    return;
  }

  string st=t.substr(1);
  string ts=t.substr(0,t.size()-1);

  f(s+t[0],st);
  f(s+t[t.size()-1],ts);

}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin>>s;

  f("",s);

  cout<<mp.size()<<endl;

}
