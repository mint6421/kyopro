
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

int n;
char a[310][310],b[310][310],c[310][310];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n;
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>b[i];
  }

  rep(i,n){
    rep(j,n){
      c[i][j]='1';
    }
  }

  rep(i,n){
    rep(j,n){
      if(b[i][j]=='0'){
        rep(k,n){
          if(a[i][k]=='1') c[k][j]='0';
        }
      }
    }
  }

  rep(i,n){
    rep(j,n){
      bool flag=false;
      rep(k,n){
        flag|=(a[i][k]=='1'&&c[k][j]=='1');
      }
      if(flag&&b[i][j]=='0'||!flag&&b[i][j]=='1'){
        cout<<-1<<endl;
        return 0;
      }
    }
  }

  rep(i,n){
    cout<<c[i]<<endl;
  }



}
