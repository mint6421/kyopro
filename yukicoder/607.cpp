

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
int Mplus(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}

int a[1100][1100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;

  cin>>n>>m;
  rep(i,m){
    rep(j,n){
      cin>>a[i][j];
    }
  }

  rep(j,n){
    FOR(i,1,m){
      a[i][j]+=a[i-1][j];
    }
  }
 
  bool flag=false;
  rep(i,m){
    int l=0,r=0;
    int s=0;
    while(r<n){
      //cout<<l<<' '<<r<<' '<<s<<endl;
      while(r<n&&s<777){
        s+=a[i][r];
        r++;
      }
      flag|=(s==777);
      while(l<r&&s>=777){
        s-=a[i][l];
        l++;
        flag|=(s==777);
      }

    }
  }

  YES(flag);



}
