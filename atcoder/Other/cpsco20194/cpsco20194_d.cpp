
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


int k,n;
int a[300000];
vector<int> s;


bool f(int m){
  int res=0;
  rep(i,s.size()){
    res+=s[i]/(m+1);
  }

//  cout<<' '<<res<<endl;
  return (res<=k);
}

main(){
  cin>>n>>k;
  int j=0;
  rep(i,n){
    cin>>a[i];
    if(a[i]!=a[j]){
      s.PB(i-j);
      j=i;
    }
  }

  s.PB(n-j);
  
  

  int r=n,l=0,m;

  while(r-l>1){
    m=(r+l)/2;
//    cout<<m<<r<<l<<endl;
    if(f(m)){
      r=m;
    }else{
      l=m;
    }
  }

  cout<<r<<endl;
}
