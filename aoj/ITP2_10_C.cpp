

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
//#define all(a) a.begin(),a.end()
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

  bitset<64> bit(0);

  int q;
  cin>>q;
  while(q--){
    int c;
    cin>>c;
    if(c==0){
      int i;
      cin>>i;
      cout<<bit[i]<<endl;
    }if(c==1){
      int i;
      cin>>i;
      bit[i]=1;
    }if(c==2){
      int i;
      cin>>i;
      bit[i]=0;
    }if(c==3){
      int i;
      cin>>i;
      bit[i]=~bit[i];
    }if(c==4){
      cout<<bit.all()<<endl;
    }if(c==5){
      cout<<bit.any()<<endl;
    }if(c==6){
      cout<<bit.none()<<endl;
    }if(c==7){
      cout<<bit.count()<<endl;
    }if(c==8){
      cout<<bit.to_ullong()<<endl;
    }

  }



}
