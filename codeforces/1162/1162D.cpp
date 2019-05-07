
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


int n,m;
set<P> s;


main(){
  cin>>n>>m;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    s.insert(P(a,b));
  }

  vector<int> v;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      v.PB(i);
      if(i*i!=n&&i!=1){
        v.PB(n/i);
      }
    }
  }

 
  for(auto t:v){
    bool flag=true;
    for(auto p:s){
       
//      cout<<p.F<<' '<<p.S<<' '<<t<<endl;
      int nx=(p.F+t)%(n+1)+(p.F+t)/(n+1);
      int ny=(p.S+t)%(n+1)+(p.S+t)/(n+1);
//      cout<<' '<<nx<<' '<<ny<<endl;
      if((s.find(P(nx,ny))==s.end())&&(s.find(P(ny,nx))==s.end())){
        flag=false;
        break;
      }
    }
    if(flag){
      cout<<"Yes"<<endl;
      return 0;
    }
  }

  cout<<"No"<<endl;

}
