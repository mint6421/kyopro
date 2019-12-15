

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
  string s;
  cin>>s;
  int b=0,w=0;
  rep(i,n){
    if(s[i]=='B') b++;
    else w++;
  }

  if(b%2&&w%2){
    cout<<-1<<endl;
    return 0;
  }

  vi ans;
  if(b%2==0){
    while(b){
      rep(i,n-1){
        if(s[i]=='B'){
          ans.PB(i+1);
          s[i]='W';
          b--;
          if(s[i+1]=='B'){
            s[i+1]='W';
            b--;
          }else{
            s[i+1]='B';
            b++;
          }
        }
      }
    }
  }else{
    while(w){
      rep(i,n-1){
        if(s[i]=='W'){
          ans.PB(i+1);
          s[i]='B';
          w--;
          if(s[i+1]=='W'){
            s[i+1]='B';
            w--;
          }else{
            s[i+1]='W';
            w++;
          }
        }
      }
    }
  }

  cout<<ans.size()<<endl;
  if(ans.size()){
    rep(i,ans.size()){
      if(i) cout<<' ';
      cout<<ans[i];
    }
    cout<<endl;
  }



}
