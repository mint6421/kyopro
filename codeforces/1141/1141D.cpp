

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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n;
queue<int> v[40];

int main(){
  cin>>n;
  string s,t;
  cin>>s>>t;
  rep(i,n){
    if(s[i]=='?')
      v[30].push(i+1);
    else
      v[s[i]-'a'].push(i+1);
  }

  vector<P> w;
  vector<int> p;
  int ans=0;
  rep(i,n){
    if(t[i]=='?'){
      ans++;
      p.PB(i+1);
    }
    else if(!v[t[i]-'a'].empty()){
      ans++;
      w.PB(P(v[t[i]-'a'].front(),i+1));
      v[t[i]-'a'].pop();
    }
    else if(!v[30].empty()){
      ans++;
      w.PB(P(v[30].front(),i+1));
      v[30].pop();
    }
  }

  rep(i,p.size()){
    rep(j,35){
      if(v[j].empty()) continue;
      w.PB(P(v[j].front(),p[i]));
      v[j].pop();
      break;
    }
  }

  cout<<ans<<endl;
  rep(i,w.size()){
    cout<<w[i].F<<' '<<w[i].S<<endl;
  }

}
