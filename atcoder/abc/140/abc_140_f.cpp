

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi v(1<<n);
  rep(i,1<<n){
    cin>>v[i];
  }
  sort(all(v));
  multiset<int> s;
  rep(i,(1<<n)-1){
    s.insert(v[i]);
  }

  vi a;
  a.PB(v[(1<<n)-1]);

  rep(i,n){
    vi w=a;
    for(auto x:a){
      auto it=s.lower_bound(x);
      if(it==s.begin()){
        Yes(false);
        return 0;
      }
      it--;
      w.PB(*it);
      s.erase(it);
    }
    sort(all(w));
    reverse(all(w));
    swap(a,w);
  }

  Yes(true);


}
