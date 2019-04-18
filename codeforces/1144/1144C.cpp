

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


int main(){
  int n;
  cin>>n;
  vector<int> v;
  rep(i,n){
    int a;
    cin>>a;
    v.PB(a);
  }

  sort(all(v));
  rep(i,n-2){
    if(v[i]==v[i+2]){
      cout<<"NO"<<endl;
      return 0;
    }
  }

  cout<<"YES"<<endl;

  int sum=0;
  rep(i,n-1){
    if(v[i]==v[i+1]) sum++;
  }
  v.PB(inf);

  cout<<n-sum<<endl;
  bool flag=false;
  rep(i,n){
    if(v[i]==v[i+1]) continue;
    if(flag) cout<<' ';
    cout<<v[i];
    flag=true;
  }
  cout<<endl;

  cout<<sum<<endl;
  flag=false;
  rrep(i,n){
    if(v[i]==v[i+1]){
      if(flag) cout<<' ';
      cout<<v[i];
      flag=true;
    }
  }
  cout<<endl;
}
