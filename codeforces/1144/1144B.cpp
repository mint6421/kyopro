

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
vector<int> a,b;

int main(){
  cin>>n;
  rep(i,n){
    int c;
    cin>>c;
    if(c%2) a.PB(c);
    else b.PB(c);
  }

  sort(all(a));
  sort(all(b));


  int sum=0;
  if(a.size()>b.size())
  rep(i,a.size()-b.size()-1){
    sum+=a[i];
  }
  if(b.size()>a.size())
  rep(i,b.size()-a.size()-1){
    sum+=b[i];
  }
  cout<<sum<<endl;

}
