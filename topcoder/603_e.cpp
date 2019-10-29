
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
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


class UnfoldingTriangles{
  public:

    int solve(vector<string> grid,int unfoldLimit){
      int ans=-1;
      int n=grid.size();
      int m=grid[0].size();
      rep(i,n){
        rep(j,m){
          if(grid[i][j]!='/') continue;
          int res=1,sum=1;
          while(res<=n+m){
            if(f(res,i,j,unfoldLimit,grid))
              ans=max(ans,sum);
            res++;
            sum+=res;
            
          }
        }
      }
      return ans;
    }

    bool f(int l,int y,int x,int lim,vector<string> s){
      
      int res=0;
      RFOR(j,x,x-l+1){
        FOR(i,y+x-j,y+l){
          
          if(!(0<=i&&i<s.size()&&0<=j&&j<=s[0].size())) return false;
          if(i+j==x+y&&s[i][j]!='/') return false;
          else if(i+j!=x+y){
            if(s[i][j]=='.') return false;
            if(s[i][j]=='/') res++;
          }
        }
      }

      //if(x==3&&y==0) cout<<l<<' '<<res<<endl;

      if(y+l<s.size()){
        FOR(j,x-l+1,x+1){
          if(s[y+l][j]=='#') return false;
        }
      }
      if(x+1<s[0].size()){
        FOR(i,y,y+l){
          if(s[i][x+1]=='#') return false;
        }
      }

      
      return (res<=lim);
    }

};


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vector<string> s(n);
  rep(i,n){
    cin>>s[i];
  }

  int l;
  cin>>l;
  UnfoldingTriangles solve;

  cout<<solve.solve(s,l)<<endl;

}

