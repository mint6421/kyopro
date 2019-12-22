

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
    string s,t;
    cin>>s>>t;
    vi alps(30,0);
    vi alpt(30,0);
    int k=s.size();
    rep(i,k){
      alps[s[i]-'a']++;
    }
    bool ans=false;
    rep(i,t.size()){
      alpt[t[i]-'a']++;
      if(i-k>=0)alpt[t[i-k]-'a']--;
      bool flag=true;
      rep(j,30){
        flag&=(alps[j]==alpt[j]);
        //cout<<j<<' '<<alps[j]<<' '<<alpt[j]<<endl;
      }

     ans|=flag;
    }
    YES(ans);

  }


}
