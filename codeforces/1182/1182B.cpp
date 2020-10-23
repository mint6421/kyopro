
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
#define int ll
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}



int h,w;
char s[600][600];


bool f(int y,int x){
  char t[600][600];
  rep(i,h){
    rep(j,w){
      t[i][j]=s[i][j];
    }
  }
  t[y][x]='.';
  int xx=x-1;
  while(xx>=0&&t[y][xx]=='*'){
    t[y][xx]='.';
    xx--;
  }
  xx=x+1;
  while(xx<w&&t[y][xx]=='*'){
    t[y][xx]='.';
    xx++;
  }
  int yy=y+1;
  while(yy<h&&t[yy][x]=='*'){
    t[yy][x]='.';
    yy++;
  }
  yy=y-1;
  while(yy>=0&&t[yy][x]=='*'){
    t[yy][x]='.';
    yy--;
  }

  rep(i,h){
    rep(j,w){
      if(t[i][j]=='*') return false;
    }
  }

 
  return true;
}


main(){
  cin>>h>>w;
  rep(i,h){
    cin>>s[i];
  }

  FOR(i,1,h-1){
    FOR(j,1,w-1){
      if(s[i][j]=='*'&&s[i-1][j]=='*'&&s[i+1][j]=='*'&&
          s[i][j-1]=='*'&&s[i][j+1]=='*'){
        if(f(i,j)){
          cout<<"YES"<<endl;
          return 0;
        }else{
          cout<<"NO"<<endl;
          return 0;
        }
      }
    }
  }


  cout<<"NO"<<endl;
}
