
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
#define vi vector<int>


bool is_prime(int x){
  if(x<2) return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0) return false;
  }
  return true;
}

int g(int n){
  int sum=n;
  while(sum>=10){
    int m=sum;
    sum=0;
    while(m){
      sum+=m%10;
      m/=10;
    }
  }
  return sum;
}

int f(vi p,int l){
  bool hash[10]={};

  FOR(i,l,p.size()){
    int d=g(p[i]);
    if(hash[d]) return i-l;
    hash[d]=true;
  }

  return p.size()-l;
}

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int k,n;

  cin>>k>>n;
  vi p;

  FOR(i,k,n+1){
    if(is_prime(i)) p.PB(i);
  }

  int ml=0,ans=0;
  rep(i,p.size()){
    int l=f(p,i);
    if(ml<=l){
      ml=l;
      ans=p[i];
    }
  }

  cout<<ans<<endl;

}


