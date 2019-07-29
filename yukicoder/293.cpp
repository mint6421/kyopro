
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

bool f(int a,int b){
  int sa=0,sb=0;
  int c=1;
  while(a||b){
    int ra=a%10,rb=b%10;
    if(ra==4&&rb==7){
      sa+=7*c;
      sb+=4*c;
    }else if(ra==7&&rb==4){
      sa+=4*c;
      sb+=7*c;
    }else{
      sa+=ra*c;
      sb+=rb*c;
    }
    c*=10;
    a/=10;
    b/=10;
  }
  //cout<<sa<<' '<<sb<<endl;

  return sa>sb;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a,b;
  cin>>a>>b;

 

  cout<<(f(a,b)?a:b)<<endl;

}
