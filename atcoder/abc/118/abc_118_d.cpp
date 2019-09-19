
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

int n,m;
bool b[10];
string dp[11000];

int size(int k){
  if(k==1) return 2;
  if(k==7) return 3;
  if(k==4) return 4;
  if(k==2||k==3||k==5) return 5;
  if(k==6||k==9) return 6;
  if(k==8) return 7;
}

string f(string s,string t,char c){
  string res="";
  int i=0;
  while(i<t.size()&&t[i]>c){
    res+=t[i];
    i++;
  }
  res+=c;
  while(i<t.size()){
    res+=t[i];
    i++;
  }

  i=0;
  if(res.size()>s.size()) return res;
  if(res.size()<s.size()) return s;
  while(i<res.size()){
    if(res[i]>s[i]) return res;
    if(res[i]<s[i]) return s;
    i++;
  }

  return res;
}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m;
  rep(i,m){
    int a;
    cin>>a;
    b[a]=true;
  }

 
  rep(i,n+1){
    rep(j,10){
      if(!b[j]) continue;
      int k=i-size(j);
      if(k<0||k!=0&&dp[k]=="") continue;
      dp[i]=f(dp[i],dp[k],j+'0');
      //cout<<i<<' '<<dp[i]<<endl;
    }
  }

  cout<<dp[n]<<endl;


}
