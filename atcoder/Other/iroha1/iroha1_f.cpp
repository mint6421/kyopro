
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


bool is_prime(int x){
  if(x<2) return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0) return false;
  }
  return true;
}



int n,k,a;
vector<int> v;

int main(){
  cin>>n>>k;

  if(k==1&&n!=1){
    cout<<n<<endl;
    return 0;
  }
  for(int i=2;i<=n;i++){
    if(!is_prime(i))continue;
    if(n%i==0){
      v.PB(i);
      n/=i;
      i--;
      a++;
      if(a==k-1){
          v.PB(n);
        break;
      }
    }
  }

  sort(all(v));
  if(v.size()==k&&v[0]!=1){
    rep(i,k){
      cout<<v[i]<<' ';
    }
    cout<<endl;
  }else{
    cout<<-1<<endl;
  }

}
