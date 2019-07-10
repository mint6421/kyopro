
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


bool is_prime(int x){
  if(x<2) return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0) return false;
  }
  return true;
}



vector< int > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  vector<int> res;
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }

  rep(i,n+1){
    if(prime[i]) res.PB(i);
  }
  return res;
}

main(){
  int n;
  cin>>n;



  vector<int> prime=prime_table(1000000);

  vector<int> v;
  int i=0;
  while(n!=1){

    int res=0;
    while(n%prime[i]==0){
      res++;
      n/=prime[i];
    }
    if(res) v.PB(res);

    if(is_prime(n)){
      v.PB(1);
      break;
    }

    i++;
  }

  int ans=0;
  rep(i,v.size()){
    ans^=v[i];
  }

  if(ans){
    cout<<"Alice"<<endl;
  }else{
    cout<<"Bob"<<endl;
  }

}
