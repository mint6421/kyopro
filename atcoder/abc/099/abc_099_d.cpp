
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
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>

int n,c;
int d[100][100];
int cc[510][510];

int f(int k,int s){
  int res=0;
  rep(i,c){
    res+=cc[k][i]*d[i][s];
  }

  return res;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>c;
  rep(i,c){
    rep(j,c){
      cin>>d[i][j];
    }
  }

  rep(i,n){
    rep(j,n){
      int x;
      cin>>x;
      cc[(i+j)%3][x-1]++;
    }
  }

  int ans=INF;
  rep(i,c){
    rep(j,c){
      rep(k,c){
        if(i==j||j==k||k==i) continue;
        int res=0;
        res+=f(0,i);
        res+=f(1,j);
        res+=f(2,k);
        ans=min(ans,res);
      }
    }
  }

  cout<<ans<<endl;


}
