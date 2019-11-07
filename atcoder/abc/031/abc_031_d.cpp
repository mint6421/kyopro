
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

int k,n;
string v[100];
string w[100];


void solve(vi a){
  vector<string> ans(k+1,"");

  FOR(i,1,k+1){
    //cout<<a[i]<<' ';
  }
  //cout<<endl;

  rep(i,n){
    string s=v[i],t=w[i];
    int j=0;

    for(char c:s){
      int x=c-'0';
      if(j+a[x]>t.size()) return;
      string res="";
      if(ans[x]==""){
        rep(l,a[x]){
          res+=t[j+l];
        }
       
      }else{
        rep(l,a[x]){
          res+=t[j+l];
        }
        if(ans[x]!=res) return;
      }
      ans[x]=res;
      j+=a[x];
    }
    if(j!=t.size()) return;
  }

  FOR(i,1,k+1){
    cout<<ans[i]<<endl;
  }
  exit(0);

}


void f(vi s,int l){
  solve(s);
  if(l>k) return;

  while(s[l]<3){
    s[l]++;
    f(s,l+1);
  }
  s[l]=1;
  f(s,l+1);

}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>k>>n;

  rep(i,n){
    cin>>v[i]>>w[i];
  }

  vi s(10,1);

  f(s,1);

}
