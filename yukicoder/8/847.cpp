

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


map<int,int> prime_factor(int n){
  map<int,int> ret;
  for(int i=2;i*i<=n;i++){
    while(n%i==0){
      ret[i]++;
      n/=i;
    }
  }
  if(n!=1) ret[n]=1;

  return ret;
}

int n,k,m;
map<int,int> mp;

int dfs(int s,auto p){
  //cout<<s<<' '<<p->F<<endl;
  if(s>m) return 0;
  if(p==mp.end()){
    //cout<<s<<endl;
    return 1;
  }

  int res=0;
  int t=1;
  rep(_,p->S+1){
    res+=dfs(s*t,++p);
    p--;
    t*=p->F;
    if(s*t>m) break;
  }

  return res;

}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  
  cin>>n>>k>>m;

  mp = prime_factor(n);
  for(auto m=mp.begin();m!=mp.end();m++){
    m->S*=k;
  }
  

  cout<<dfs(1,mp.begin())<<endl;
  
}
