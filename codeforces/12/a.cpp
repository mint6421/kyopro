
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

int n;
string s;

int f(int m){
  char t[5]="ACTG";
  int res=0;
  rep(i,4){
    int r=abs(s[i+m]-t[i]);
    if(s[i+m]>t[i]){
      r=min(r,t[i]+'Z'-'A'+1-s[i+m]);
    }
    else{
      r=min(r,s[i+m]+'Z'-'A'+1-t[i]);
    }
    res+=r;
  }

  return res;
}


int main(){
  cin>>n;
  cin>>s;

  int ans=inf;

  rep(i,n-3){
    ans=min(ans,f(i));
  }

  cout<<ans<<endl;
}
