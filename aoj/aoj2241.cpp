#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>

int n,u,v,m;
int ux[510],uy[510];
int vx[510],vy[510];
int uu[2],vv[2];
map<int,P> mu,mv;

int main(){
  cin>>n>>u>>v>>m;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int a;
      cin>>a;
      mu[a]=P(i,j);
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int a;
      cin>>a;
      mv[a]=P(i,j);
    }
  }

  int uc=0,vc=0;

  while(m--){
    int a;
    cin>>a;
//    cout<<a<<endl;
    if(mu.find(a)!=mu.end()){
      P pu=mu[a];
      int x=pu.second,y=pu.first;
//      cout<<"u  "<<x<<' '<<y<<endl;
      ux[x]++;
      uy[y]++;
      if(ux[x]==n) uc++;
      if(uy[y]==n&&n!=1) uc++;
      if(x==y&&n!=1){
        uu[0]++;
        if(uu[0]==n) uc++;
      }
      if(x+y+1==n&&n!=1){
        uu[1]++;
        if(uu[1]==n) uc++; 
      }
    }

    if(mv.find(a)!=mv.end()){
      P pv=mv[a];
      int x=pv.second,y=pv.first;
//      cout<<"v   "<<x<<' '<<y<<endl;
      vx[x]++;
      vy[y]++;
      if(vx[x]==n) vc++;
      if(vy[y]==n&&n!=1) vc++;
      if(x==y){
        vv[0]++;
        if(vv[0]==n&&n!=1) vc++;
      }
      if(x+y+1==n){
        vv[1]++;
        if(vv[1]==n&&n!=1) vc++; 
      }
    }
//    cout<<uc<<' '<<vc<<endl;

    if(uc>=u&&vc>=v){
      cout<<"DRAW"<<endl;
      return 0;
    }
    if(uc>=u){
      cout<<"USAGI"<<endl;
      return 0;
    }
    if(vc>=v){
      cout<<"NEKO"<<endl;
      return 0;
    }
    
  }

  cout<<"DRAW"<<endl;


}
