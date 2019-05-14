
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


int h,w,n;
int sr,sc;
string s,t;
int sx1,sx2,sy1,sy2;

int main(){
  cin>>h>>w>>n;
  cin>>sr>>sc;
  sx1=sc;sx2=sc;
  sy1=sr;sy2=sr;

  cin>>s>>t;

  rep(i,n){
    if(s[i]=='R')
      sx1++;
    if(s[i]=='L')
      sx2--;
    if(s[i]=='D')
      sy1++;
    if(s[i]=='U')
      sy2--;

    if(sx2<1||sx1>w||sy2<1||sy1>h){
      cout<<"NO"<<endl;
      return 0;
    }

    if(t[i]=='R')
      sx2=min(sx2+1,w-1);
    if(t[i]=='L')
      sx1=max(sx1-1,1);
    if(t[i]=='D')
      sy2=min(sy2+1,h-1);
    if(t[i]=='U')
      sy1=max(sy1-1,1);
  }

  cout<<"YES"<<endl;
}
