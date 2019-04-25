

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

int x;
int ans=0;

int f(int m){
  int r=1;
  int res=-1;
  int n=0;
  while(r<m){
//    cout<<r<<' '<<m<<endl;
//    cout<<(r&m)<<endl;
    if((r&m)==0){
      res=n;
    }
    r*=2;
    n++;
  }

  return res+1;
}

int main(){
  cin>>x;
  int k=0;
  int m=f(x);
  vector<int> v;
  while(m!=0){
//    cout<<m<<endl;
    v.PB(m);
    k++;
    x= x^((1<<m)-1);
//    cout<<x<<endl;
    if(f(x)==0) break;
    x++;
    k++;
    m = f(x);
//    cout<<x<<endl;
  }
//  cout<<x<<endl;

  cout<<k<<endl;
  if(v.size()==0) return 0;
  rep(i,v.size()){
    cout<<v[i]<<' ';
  }
  cout<<endl;
}
