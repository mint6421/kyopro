

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
  int n;
  cin>>n;
  vector<bitset<64>> mask(n,bitset<64>(0));
  rep(i,n){
    int m;
    cin>>m;
    while(m--){
      int k;
      cin>>k;
      mask[i].set(k);
    }
  }

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
      int m;
      cin>>m;
      bit|=mask[m];
    }if(c==2){
      int m;
      cin>>m;
      bit&=(~mask[m]);
    }if(c==3){
      int m;
      cin>>m;
      bit=bit^mask[m];
    }if(c==4){
      int m;
      cin>>m;
      cout<<((bit&mask[m])==mask[m])<<endl;
    }if(c==5){
      int m;
      cin>>m;
      cout<<(bit&mask[m]).any()<<endl;
    }if(c==6){
      int m;
      cin>>m;
      cout<<(((~bit)&mask[m])==mask[m])<<endl;
    }if(c==7){
      int m;
      cin>>m;
      cout<<(bit&mask[m]).count()<<endl;
    }if(c==8){
      int m;
      cin>>m;
      cout<<(bit&mask[m]).to_ullong()<<endl;
    }

  }



}
