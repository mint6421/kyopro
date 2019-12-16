

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
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    set<string> set[4];
    map<string,int> mp;
    rep(i,n){
      string s;
      cin>>s;
      if(s[0]=='0'&&s[s.size()-1]=='0') set[0].insert(s);
      if(s[0]=='0'&&s[s.size()-1]=='1') set[1].insert(s);
      if(s[0]=='1'&&s[s.size()-1]=='0') set[2].insert(s);
      if(s[0]=='1'&&s[s.size()-1]=='1') set[3].insert(s);
      mp[s]=i+1;
    }

    if(set[0].size()&&set[3].size()&&set[1].empty()&&set[2].empty()){
      cout<<-1<<endl;
      continue;
    }

    vi ans;
    int a=set[1].size(),b=set[2].size();
    for(auto p:set[1]){
      if(abs(a-b)<=1)break;
      if(a<b) break;
      string t=p;
      reverse(all(t));
      if(set[2].find(t)!=set[2].end()) continue;
      ans.PB(mp[p]);
      a--;
      b++;
    } 
    for(auto p:set[2]){
      if(abs(a-b)<=1)break;
      if(a>b) break;
      string t=p;
      reverse(all(t));
      if(set[1].find(t)!=set[1].end()) continue;
      ans.PB(mp[p]);
      a++;
      b--;
    }

    if(abs(a-b)>1){
      cout<<-1<<endl;
      continue;
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size()){
      if(i) cout<<' ';
      cout<<ans[i];
    }
    cout<<endl;


  }



}
