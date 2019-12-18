

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
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int r,c;
  cin>>r>>c;
  if(r==1&&c==1){
    cout<<0<<endl;
    return 0;
  }

  if(c==1){
    rep(j,r){
      cout<<j+2;
      cout<<endl;
    }
    //cout<<endl;
    return 0;
  }

  if(r==1){
    rep(j,c){
      if(j) cout<<' ';
      cout<<j+2;
      
    }
    cout<<endl;
    return 0;
  }

  int a[510][510];

  
  rep(i,r){
    rep(j,c){    
      if(j) cout<<' ';
      cout<<(i+c+1)*(j+1);
     
      a[i][j]=(i+c+1)*(j+1);
    }
    cout<<endl;
  }
  
  /*
  bool b[1000]={};

  rep(j,r){
    int g=a[0][j];
    rep(i,c){
        g=__gcd(g,a[i][j]);
    }
    cout<<g<<' ';
    //if(b[g]) cout<<g<<"                    "<<endl;
    b[g]=true;
  }

  rep(i,c){
    int g=a[i][0];
    rep(j,r){
      g=__gcd(g,a[i][j]);
    }
    cout<<g<<' ';
    //if(b[g]) cout<<g<<"                    "<<endl;
    b[g]=true;
  }
  cout<<endl;

  */

}
