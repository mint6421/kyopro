

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

  int xl=-150,xr=150;
  int dl,dr;
  cout<<"? -150 0 0"<<endl;
  cin>>dl;
  cout<<"? 150 0 0"<<endl;
  cin>>dr;

  while(xr-xl>1){
    int x=(xl+xr)/2;
    cout<<"? "<<x<<" 0 0"<<endl;
    int d;
    cin>>d;
    if(dl>dr){
      dl=d;
      xl=x;
    }
    else{
      dr=d;
      xr=x;
    }
  }
  int x=(dl>dr?xr:xl);

 
  int yl=-150,yr=150;
  
  cout<<"? 0 -150 0"<<endl;
  cin>>dl;
  cout<<"? 0 150 0"<<endl;
  cin>>dr;

  while(yr-yl>1){
    int y=(yl+yr)/2;
    cout<<"? 0 "<<y<<" 0"<<endl;
    int d;
    cin>>d;
    if(dl>dr){
      dl=d;
      yl=y;
    }
    else{
      dr=d;
      yr=y;
    }
  }
  int y=(dl>dr?yr:yl);

  int zl=-150,zr=150;
  
  cout<<"? 0 0 -150"<<endl;
  cin>>dl;
  cout<<"? 0 0 150"<<endl;
  cin>>dr;

  while(zr-zl>1){
    int z=(zl+zr)/2;
    cout<<"? 0 0 "<<z<<endl;
    int d;
    cin>>d;
    if(dl>dr){
      dl=d;
      zl=z;
    }
    else{
      dr=d;
      zr=z;
    }
  }
  int z=(dl>dr?zr:zl);


  cout<<"! "<<x<<' '<<y<<' '<<z<<endl;

}
