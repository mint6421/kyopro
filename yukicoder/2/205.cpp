
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

  int n;
  cin>>n;
  vector<string> v(n);
  rep(i,n){
    cin>>v[i];
    v[i].PB((char)('z'+1));
  }
  sort(all(v));

  string ans="";

  while(!v.empty()){
    string s=v[0];
    v.erase(v.begin());
    ans+=s[0];
    s.erase(s.begin());
    if(s[0]==(char)('z'+1)) continue;
    s+=(char)('z'+1);
    v.PB(s);
    sort(all(v));
  }

  cout<<ans<<endl;

}
