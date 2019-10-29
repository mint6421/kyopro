
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
#define IP pair<int,P>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}

map<string,bool> mp;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  string s;
  cin>>s;
  mp[s]=true;
  int n=s.size();
  string t;
  rep(i,n) t+='o';
  int ans=1;
  vector<string> v;
  v.PB(s);
  while(mp.find(t)==mp.end()){
    vector<string> w;
    for(string u:v){
      rep(j,n){
        string res;
        rep(i,n){
          char c='x';
          if(u[i]=='o') c='o';
          if(s[(i+j)%n]=='o') c='o';
          res+=c;
        }
        //cout<<res<<endl;
        if(mp.find(res)==mp.end()){
          mp[res]=true;
          w.PB(res);
        }
      }
    }
    v=w;
    ans++;
  }

  cout<<ans<<endl;

}
