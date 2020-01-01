

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
  vector<P> p(n);
  rep(i,n){
    cin>>p[i].F>>p[i].S;
    p[i].F+=1e6;
    p[i].S+=1e6;
  }

  while(true){
    vector<vi> cnt(2,vi(2,0));
    rep(i,n){
      cnt[p[i].F%2][p[i].S%2]++;
    }
    if(cnt[0][0]+cnt[1][1]>0&&cnt[0][1]+cnt[1][0]>0){
      vi a;
      rep(i,n){
        if((p[i].F+p[i].S)%2==0) a.PB(i);
      }
      cout<<a.size()<<endl;
      for(auto it:a){
        cout<<it+1<<' ';
      }
      cout<<endl;
      return 0;
    }
    if(cnt[0][0]+cnt[0][1]>0&&cnt[1][1]+cnt[1][0]>0){
      vi a;
      rep(i,n){ 
        if(p[i].F%2==0) a.PB(i);
      }
      cout<<a.size()<<endl;
      for(auto it:a){
        cout<<it+1<<' ';
      }
      cout<<endl;
      return 0;
    }
    int x,y;
    rep(i,2){
      rep(j,2){
        if(cnt[i][j]>0){
          x=i;
          y=i;
        }
      }
    }

    rep(i,n){
      p[i].F=(p[i].F-x)/2;
      p[i].S=(p[i].S-y)/2;
    }
  }



}
