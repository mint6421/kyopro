
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n;
char s[1100][1100];

int main(){
  cin>>n;
  rep(i,n){
    rep(j,n){
      s[i][j]='.';
    }
  }

  rep(i,n){
    rep(j,n){
      if((i*2+j)%5!=0) continue;
      s[i][j]='X';
    }
  }

  rep(i,n){
    rep(j,n){
      bool flag=false;
      rep(k,4){
        int x=j+vx[k],y=i+vy[k];
        if(!(0<=x&&x<n&&0<=y&&y<n)) continue;
        if(s[y][x]=='X') flag=true;
      }
      if(!flag) s[i][j]='X';
    }
  }

  int ans=0;
  rep(i,n){
    rep(j,n){
      if(s[i][j]=='X') ans++;
    }
    cout<<s[i]<<endl;
  }
//    cout<<ans<<endl;
}
