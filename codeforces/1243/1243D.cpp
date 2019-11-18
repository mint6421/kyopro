

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}


int n,m;
set<int> es[110000];
set<int> s;
bool b[110000];
queue<int> q;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  
  cin>>n>>m;
  
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a].insert(b);
    es[b].insert(a);
  }


  rep(i,n){
    s.insert(i);
  }
  int ans=0;
  rep(i,n){
    if(b[i]) continue;
    ans++;
    s.erase(i);
    q.push(i);
    while(q.size()){
      int p=q.front(); q.pop();
      vi er;
      for(int x:s){
        if(es[p].count(x)==0){
          b[x]=true;
          q.push(x);
          er.PB(x);
        }
      }
      for(int x:er){
        s.erase(x);
      }
    }
  }

  cout<<ans-1<<endl;


}
