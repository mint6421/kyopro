
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M 1000000007
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
#define S seconnd
#define PB push_back
#define int ll

int a[1000][1000];
int H,W,h,w;

signed main(){
  cin>>H>>W>>h>>w;
  rep(i,H){
    rep(j,W){
      a[i][j]=1000;
    }
  }

  rep(i,H){
    rep(j,W){
      if((i+1)%h==0&&(j+1)%w==0)
        a[i][j]=-1000*(h*w-1)-1;
    }
  }


  int sum=0;
  rep(i,H){
    rep(j,W){
      sum+=a[i][j];
    }
  }
  

  if(sum<=0){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
    rep(i,H){
      rep(j,W){
        if(j==0) cout<<a[i][j];
        else cout<<' '<<a[i][j];
      }
      cout<<endl;
    }
  }

}
