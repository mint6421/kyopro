
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



vector< int > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  vector<int> a(n,0);
  int t=1;
  rep(i,n){
    if(prime[i]){
      a[i]=t++;
    }
  }

  return a;
}


main(){
  int n;
  cin>>n;
  multiset<int> b;
  rep(i,2*n){
    int a;
    cin>>a;
    b.insert(-a);
  }

  vector<int> a;

  vector<int> prime = prime_table(3000000);

  for(auto s:b){
    int t=-s;
    //cout<<t<<endl;
    if(prime[t]){
      a.PB(prime[t]);
      b.erase(b.find(-prime[t]));
    }else{
      a.PB(t);
      FOR(i,2,t){
        if(t%i==0){
          t*=-1;
          b.erase(b.find(t/i));
          break;
        }
      }
    }
  }

  rep(i,n){
    cout<<a[i]<<' ';
  }
  cout<<endl;


}
