

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  vi coin;
  int s=1;
  while(s*(s+1)/2<1e7){
    coin.PB(s*(s+1)/2);
    //cout<<s*(s+1)/2<<endl;
    s++;
  }
  //cout<<coin.size()<<endl;
  
  int n;
  cin>>n;
  if(find(all(coin),n)!=coin.end()){
    cout<<1<<endl;
  }else{
    bool flag=false;
    rep(i,coin.size()){
      FOR(j,i,coin.size()){
        if(coin[i]+coin[j]==n){
          flag=true;
        }
      }
    }
    if(flag) cout<<2<<endl;
    else cout<<3<<endl;
  }

  
}
