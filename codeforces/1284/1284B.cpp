

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vector<vi> v(n);
  int ans=0;
  vi s(1100000,0);
  int m=n;
  rep(i,n){
    int k;
    cin>>k;
    rep(j,k){
      int a;
      cin>>a;
      v[i].PB(a);
    }
    bool flag=false;
    
    FOR(j,1,k){
      if(v[i][j-1]<v[i][j]){
        ans+=2*m-1;
        m--;
        flag=true;
        v[i].clear();
        break;
      }
    }
    
    if(flag) continue;
    sort(all(v[i]));
    s[v[i][k-1]]++;
  }

  rrep(i,1000000){
    s[i]+=s[i+1];
  }

  rep(i,n){
    if(v[i].empty()) continue;
    //cout<<v[i][0]<<' '<<s[v[i][0]+1]<<endl;
    ans+=s[v[i][0]+1];
  }

  cout<<ans<<endl;



}
