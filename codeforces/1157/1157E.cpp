
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
vector<int> a,b,c;

int main(){
  cin>>n;
  rep(i,n){
    int x;
    cin>>x;
    a.PB(x);
  }
  rep(i,n){
    int x;
    cin>>x;
    b.PB(x);
  }
  sort(all(b));

  rep(i,n){
    int x=(n-a[i])%n;
    int it=lower_bound(all(b),x)-b.begin();
    int it1=upper_bound(all(b),x)-b.begin();
    
    if(it>=b.size()) it--;
    if(it1>=b.size()) it1--;
    cout<<it<<' '<<it1<<endl;
    if((a[i]+b[it])%n>(a[i]+b[it1]%n)){
      c.PB((a[i]+b[it1]%n));
      b.erase(b.begin()+it1);
    }
    else{
      c.PB((a[i]+b[it])%n);
      b.erase(b.begin()+it);
    }
  }

  rep(i,n){
    cout<<c[i]<<' ';
  }
  cout<<endl;


}
