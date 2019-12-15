

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}



template< typename T >
vector< T > slide_min(const vector< T > &v, int k)
{
  deque< int > deq;
  vector< T > ret;
  for(int i = 0; i < v.size(); i++) {
    while(!deq.empty() && v[deq.back()] >= v[i]) {
      deq.pop_back();
    }
    deq.push_back(i);
    if(i - k + 1 >= 0) {
      ret.emplace_back(v[deq.front()]);
      if(deq.front() == i - k + 1) deq.pop_front();
    }
  }
  return ret;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  int n,l;
  cin>>n>>l;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }

  vi v=slide_min(a,l);
  rep(i,n-l+1){
    if(i) cout<<' ';
    cout<<v[i];
  }
  cout<<endl;


}
