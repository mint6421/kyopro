
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int h,w;
  bool d[100][100]={};
  d[1][1]=true;
  cin>>h>>w;

  int s=h*w-2;
  if(!(h==1||w==1)) s-=2;
  else s--;

  if(s%2){
    cout<<"First"<<endl;
    if(h>1){
      cout<<2<<' '<<1<<endl;
      d[2][1]=true;
    }
    else{
      cout<<1<<' '<<2<<endl;
      d[1][2]=true;
    }
  }else{
    cout<<"Second"<<endl;
  }

  int x,y;
  while(true){
    cin>>x>>y;
    if(x==-1) break;
    if(x==h&&y==w-1||x==h-1&&y==w){
      cout<<h<<' '<<w<<endl;
      
    }else{
      d[x][y]=true;
      bool flag=false;
      FOR(i,1,h+1){
        FOR(j,1,w+1){
          if(flag) break;
          if(i==h&&j==w-1||i==h-1&&j==w) continue;
          if(!d[i][j]){
            cout<<i<<' '<<j<<endl;
            d[i][j]=true;
            flag=true;
          }
        }
      }
    }
  }



}
