

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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n,a,b;
int s[300000];


int main(){
  cin>>n>>a>>b;
  rep(i,n){
    cin>>s[i];
  }

  int bb=b;
  rep(i,n){
    if(a==0&&bb==0){
      cout<<i<<endl;
      return 0;
    }

    if(!s[i]){
      if(bb>0) bb--;
      else a--;
    }
    else{
      if(a>0&&bb<b){
        a--;
        bb++;
      }
      else if(bb>0)
        bb--;
      else
        a--;
    }
  }

  cout<<n<<endl;
}
