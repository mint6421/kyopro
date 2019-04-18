

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
int a[300000];

int main(){
  cin>>n;
  rep(i,n-1){
    int c;
    cin>>c;
    a[i+1]+=a[i]+c;
  }

  int m=inf;
  rep(i,n){
    m=min(m,a[i]);
  }

  int b[300000];
  rep(i,n){
    a[i]-=m;
    b[i]=a[i];
  }

  sort(b,b+n);
  rep(i,n){
    if(b[i]!=i){
      cout<<-1<<endl;
      return 0;
    }
  }

  rep(i,n){
    cout<<a[i]+1<<' ';
  }
  cout<<endl;
}
