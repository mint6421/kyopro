
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



main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  vector<int> a(n+1);
  rep(i,n){
    cin>>a[i+1];
  }

  vector<int> b;
  bool c[300000]={};

  RFOR(i,n,1){
    int res=0;
    int j=i;
    while(j<=n){
      if(c[j]) res=(res+1)%2;
      j+=i;
    }
    if(res!=a[i]){
      b.PB(i);
      c[i]=true;
    }
  }

  sort(all(b));
  cout<<b.size()<<endl;
  for(int t:b){
    cout<<t<<endl;

  }

}
