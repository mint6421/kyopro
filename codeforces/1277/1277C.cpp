

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

  int q;
  cin>>q;
  while(q--){
    string s;
    cin>>s;
    vi ans;
    rep(i,s.size()){
      if(i<s.size()-2){
        if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
          ans.PB(i+2);
        }if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
          if(i<s.size()-4&&s[i+3]=='n'&&s[i+4]=='e'){
            ans.PB(i+3);
            i+=2;
          }else{
            ans.PB(i+2);
          }
        }
      }
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()){
      if(i) cout<<' ';
      cout<<ans[i];
    }
    cout<<endl;
  }


}
