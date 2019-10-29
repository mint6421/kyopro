
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

int n,w;
vector<P> v;


void knapsack1(){
  map<int,int> mp1,mp2;
  int bit=0;
  while(bit<(1<<(n/2))){
    int s=0,t=0;
    rep(i,n/2){
      if((1<<i)&bit){
        s+=v[i].F;
        t+=v[i].S;
      }
    }
    //cout<<s<<' '<<t<<endl;
    if(t<=w) mp1[t]=max(mp1[t],s);
    bit++;
  }

  bit=0;
  while(bit<(1<<(n/2+n%2))){
    int s=0,t=0;
    rep(i,n/2+n%2){
      if((1<<i)&bit){
        s+=v[n/2+i].F;
        t+=v[n/2+i].S;
      }
    }
    if(t<=w) mp2[t]=max(mp2[t],s);
    bit++;
  }

  int ans=0;

  for(auto p1:mp1){
    for(auto p2:mp2){
      if(p1.F+p2.F>w) continue;
      ans=max(ans,p1.S+p2.S);
    }
  }


  cout<<ans<<endl;

}


void knapsack2(){

  int b[210000]={};
  rep(i,210000){
    b[i]=INF;
  }
  b[0]=0;
  rep(i,n){
    rrep(j,200000){
      if(b[j]==INF) continue;
      b[j+v[i].F]=min(b[j+v[i].F],b[j]+v[i].S);      
    }
  }
  rrep(i,200000){
    if(b[i]<=w){
      cout<<i<<endl;
      return ;
    }

  }

}


void knapsack3(){
  int b[210000]={};

  rep(i,n){
    rrep(j,w){
      b[j+v[i].S]=max(b[j+v[i].S],b[j]+v[i].F);
    }
  }

  int ans=0;
  rep(i,w+1){
    ans=max(ans,b[i]);
  }

  cout<<ans<<endl;
}
  

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>w;
  v=vector<P>(n);
  rep(i,n){
    cin>>v[i].F>>v[i].S;
  }
  sort(all(v));

  if(n<=30) knapsack1();
  else if(v[n-1].F<=1000) knapsack2();
  else knapsack3();


}
