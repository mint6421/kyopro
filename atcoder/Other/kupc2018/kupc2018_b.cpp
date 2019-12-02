

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

int h,w;
char s[110][110];
int x;

void g(vi v){
  int nx=x;
  int nh=h-2;
  rep(i,v.size()){
    nx+=v[i];
    if(!(0<=nx&&nx<w)) return;
    if(s[nh][nx]=='x') return;
    nh--;
  }

  rep(i,v.size()){
    if(v[i]==-1) cout<<'L';
    else if(v[i]==0) cout<<'S';
    else cout<<'R';
  }
  cout<<endl;
  exit(0);
}


void f(vi v){
  if(v.size()==h-1){
    g(v);
    return;
  }

  FOR(i,-1,2){
    v.PB(i);
    f(v);
    v.erase(v.end()-1);
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>h>>w;
  rep(i,h){
    cin>>s[i];
    rep(j,w) if(s[i][j]=='s') x=j;
  }

  f(vi());

  cout<<"impossible"<<endl;


}
