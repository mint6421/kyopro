
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

string s;
string t;
int k;
int n;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>s;
  n=s.size();
  rep(_,3){
    rep(i,s.size()){
      t+=s[i];
    }
  }

  int a[3]={};

  rep(i,t.size()){
    if(i&&t[i]==t[i-1]){
      t[i]=' ';
      a[i/n]++;
    }
  }

  cin>>k;

  bool flag=true;
  rep(i,n){
    if(i) flag&=s[i]==s[i-1];
  }
  
  if(flag){
    cout<<n*k/2<<endl;
    return 0;
  }


  int ans=0;
  if(k==1) ans=a[0];
  else ans=a[0]+a[2]+a[1]*(k-2);

  cout<<ans<<endl;


}
