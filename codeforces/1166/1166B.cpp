
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


main(){
  int k;
  cin>>k;

  int n=-1,m=-1;
  for(int i=5;i*i<=k;i++){
    if(k%i==0){
      n=i;
      m=k/i;
    }
  }


  if(n==-1){
    cout<<-1<<endl;
    return 0;
  }
//  cout<<n<<' '<<m<<endl;

  char c[100000]={};
  rep(i,10000){
    c[i]='g';
  }
  c[0]='a';
  c[1]='i';
  c[2]='u';
  c[3]='e';
  c[4]='o';

  rep(i,n){
    rep(j,m){
//      cout<<' '<<i+j<<' '<<n<<' '<<endl;
      int b=(i+j)%n;
      cout<<c[b];
    }
 
  }

  cout<<endl;
}
