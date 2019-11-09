
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m,d;
  cin>>n>>m>>d;
  vi v(n+1);
  rep(i,n+1){
    v[i]=i;
  }

  vi amida;
  rep(i,m){
    int a;
    cin>>a;
    amida.PB(a);
  
  }
  reverse(all(amida));
  rep(i,m){
    swap(v[amida[i]],v[amida[i]+1]);
  }

  /*
  FOR(i,1,n+1){
    cout<<v[i]<<' ';
  }
  cout<<endl;
  */

  vector<vi> roop; 
  bool b[n+1]={};
  int roopk[n+1];
  int it[n+1];
  int i=1;
  while(i<=n){
    if(b[i]){
      i++;
      continue;
    }
    vi res;
    int j=i;
    while(!b[j]){
      roopk[j]=roop.size();
      it[j]=res.size();
      b[j]=true;
      res.PB(j);
      j=v[j];
    }
    roop.PB(res);
    i++;
  }

  /*
  FOR(i,1,n+1){
    cout<<roopk[i]<<' '<<it[i]<<endl;
  }
  */

  FOR(i,1,n+1){
  //  int k=d%roop[roopk[i]];

    cout<<roop[roopk[i]][(it[i]+d)%roop[roopk[i]].size()]<<endl;
  }


}
