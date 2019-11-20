

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  
  vector<char> v;
  for(char c='a';c<='z';c++) v.PB(c);
  for(char c='A';c<='Z';c++) v.PB(c);
  for(char c='0';c<='9';c++) v.PB(c);

  int t;
  cin>>t;
  while(t--){
    int y,x,k;
    cin>>y>>x>>k;
    char s[110][110];
    int r=0;
    rep(i,y){
      cin>>s[i];
      rep(j,x) if(s[i][j]=='R') r++;
    }
    char ans[110][110];
    int i=0,j=0;
    int sum=0;
    int c=0;
    int rk=r/k;
    int rc=r%k;
    while(i<y){
      while(j<x&&j>=0){
        ans[i][j]=v[c];
        if(k>0&&s[i][j]=='R'){
          sum++;
          if(rc==0&&sum==rk||sum>rk){
            if(c<k-1)c++;
            sum=0;
            if(rc>0) rc--;
          }
        }
        if(i%2==0)j++;
        else j--;
      }
      if(j==x) j--;
      else j++;
      i++;
    }

    rep(i,y){
      rep(j,x){
        cout<<ans[i][j];
      }
      cout<<endl;
    }
  }


}
