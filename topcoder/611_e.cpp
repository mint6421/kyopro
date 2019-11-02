
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
const int vx[8] = {1,1,2,2,-1,-1,-2,-2};
const int vy[8] = {2,-2,1,-1,2,-2,1,-1};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
//#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


class KnightsTour{
  public:
    int visitedPositions(vector<string> board){
      P s;
      bool b[10][10]={};
      rep(i,8){
        rep(j,8){
          if(board[i][j]=='*') b[i][j]=true;
          if(board[i][j]=='K'){
            b[i][j]=true;
            s=P(i,j);
          }
        }
      }

      queue<P> q;
      q.push(s);
      int ans=0;
      while(q.size()){
        P p=q.front(); q.pop();
        cout<<p.F<<' '<<p.S<<endl;
        ans++;
        vector<IP> v;
        rep(k,8){
          int y=p.F+vy[k],x=p.S+vx[k];
          if(!(0<=x&&x<8&&0<=y&&y<8)) continue;
          if(b[y][x]) continue;
          int res=0;
          rep(i,8){
            int yy=y+vy[i],xx=x+vx[i];
            if(!(0<=xx&&xx<8&&0<=yy&&yy<8)) continue;
            if(!b[yy][xx]) res++;
          }
          v.PB(IP(res,P(y,x)));
        }
        sort(all(v));
        if(v.size()){
          b[v[0].S.F][v[0].S.S]=true;
          q.push(v[0].S);
        }
      }

      return ans;
    }
};



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  vector<string> s(8);
  rep(i,8){
    cin>>s[i];
  }

  KnightsTour solve;

  cout<<solve.visitedPositions(s)<<endl;


}
