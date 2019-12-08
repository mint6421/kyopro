

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

int n,m;
int c[200100];
int nextl[200100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m;
  rep(i,n+1){
    nextl[i]=i+1;
    c[i]=-1;
  }

  while(m--){
    int l,r;
    char d;
    cin>>l>>r>>d;
    l--;r--;
    int k;
    if(d=='Y') k=0;
    else if(d=='K') k=1;
    else k=2;
    while(l<=r){
      if(c[l]==-1){
        c[l]=k;
      }
      int nl=nextl[l];
      nextl[l]=max(nextl[l],r+1);
      l=nl;
    }
  }

  int cnt[3]={};
  rep(i,n){
    if(c[i]==-1) continue;
    cnt[c[i]]++;
  }

  cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<endl;


}
