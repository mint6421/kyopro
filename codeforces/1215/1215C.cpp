
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  vi ab,ba;
  rep(i,n){
    if(s[i]=='a'&&t[i]=='b') ab.PB(i+1);
    if(s[i]=='b'&&t[i]=='a') ba.PB(i+1);
  }

  //cout<<ab.size()<<ba.size()<<endl;

  if((ab.size()+ba.size())%2){
    cout<<-1<<endl;
    return 0;
  }


  vector<P> ans;

  if(ab.size()%2==0&&ba.size()%2==0){
    for(int i=0;i*2<ab.size();i++){
      ans.PB(P(ab[i*2],ab[i*2+1]));
    }
    for(int i=0;i*2<ba.size();i++){
      ans.PB(P(ba[i*2],ba[i*2+1]));
    }
  }else{
    for(int i=0;i*2+2<ab.size();i++){
      ans.PB(P(ab[i*2],ab[i*2+1]));
    }
    for(int i=0;i*2+2<ba.size();i++){
      ans.PB(P(ba[i*2],ba[i*2+1]));
    }
    int j=ab.size()-1,k=ba.size()-1;
    ans.PB(P(ab[j],ab[j]));
    ans.PB(P(ab[j],ba[k]));
  }

  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i].F<<' '<<ans[i].S<<endl;
  }


  }
