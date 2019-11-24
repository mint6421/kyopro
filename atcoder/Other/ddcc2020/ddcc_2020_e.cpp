

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

  int n;
  cin>>n;
  char c[300];
  char res[300]={};
  rep(i,2*n) res[i]='c';
  P t;
  int l=0,r=n;
  cout<<'?';
  rep(i,n){
    cout<<' '<<i+1;
  }
  cout<<endl;
  string s;
  cin>>s;
  if(s=="Red") c[0]='R';
  else c[0]='B';

  while(r-l>1){
    
    int m=(r+l)/2;
    
    cout<<'?'; 
    rep(i,n){
      cout<<' '<<i+m+1;
    }
    cout<<endl;
    string s;
    cin>>s;
    if(s=="Red") c[m]='R';
    else c[m]='B';
    if(c[0]==c[m]){
      l=m;
    }else{
      r=m;
    }
  }
 
  t=P(l+1,l+n-1);  
  //cout<<l<<' '<<l+n-2<<endl;

  vi red,blue;
  rep(i,2*n){
    if(t.F<=i&&i<=t.S) continue;
    cout<<'?';
    FOR(j,t.F,t.S+1){
      cout<<' '<<j+1;
    }
    cout<<' '<<i+1<<endl;
    string s;
    cin>>s;
    if(s=="Red"){
      res[i]='R';
      red.PB(i);
    }
    else{
      res[i]='B';
      blue.PB(i);
    }
  }

  rep(i,2*n){
    if(t.F<=i&&i<=t.S){
      cout<<'?';
      rep(j,n/2) cout<<' '<<red[j]+1;
      rep(j,n/2) cout<<' '<<blue[j]+1;
      cout<<' '<<i+1<<endl;
      string s;
      cin>>s;
      if(s=="Red"){
        res[i]='R';
        red.PB(i);
      }
      else{
        res[i]='B';
        blue.PB(i);
      }
    }
  }

  cout<<'!'<<' '<<res<<endl;


}
