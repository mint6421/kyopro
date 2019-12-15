

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
  string s;
  while(q--){
    cin>>s;
    int a=0,b=0,c=0,d=0;
    rep(i,s.size()){
      if(s[i]=='U') a++;
      if(s[i]=='D') b++;
      if(s[i]=='R') c++;
      if(s[i]=='L') d++;
    }
    int x=min(a,b),y=min(c,d);
    //cout<<x<<' '<<y<<endl;
    if(x==0&&y==0){
      cout<<0<<endl;
      cout<<endl;
      continue;
    }
    if(x==0){
      cout<<2<<endl;
      cout<<"RL"<<endl;
      continue;
    }
    if(y==0){
      cout<<2<<endl;
      cout<<"UD"<<endl;
      continue;
    }
    cout<<2*x+2*y<<endl;
    rep(i,x){
      cout<<'U';
    }
    rep(i,y){
      cout<<'R';
    }
    rep(i,x){
      cout<<'D';
    }
    rep(i,y){
      cout<<'L';
    }
    cout<<endl;
  }


}
