

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k;
  cin>>n>>k;
  vi a(3);
  rep(i,3){
    cin>>a[i];
  }

  string s;
  cin>>s;
  vector<bool> b(n,false);

  int ans=0;
  rep(i,n){
    bool flag=false;
    if(i<k) flag=true;
    else if(s[i-k]!=s[i]||b[i-k]){
      flag=true;
    }

    if(flag){
      if(s[i]=='r') ans+=a[2];
      if(s[i]=='s') ans+=a[0];
      if(s[i]=='p') ans+=a[1];
    }else{
      b[i]=true;
    }
  }

  cout<<ans<<endl;
}
