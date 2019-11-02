
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

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    string s;
    cin>>s;

    string ans;
    int win=0;
    rep(i,n){
      if(s[i]=='R'){
        if(b>0){
          win++;
          ans.PB('P');
          b--;
        }else{
          ans.PB('.');
        }
      }else if(s[i]=='P'){
        if(c>0){
          win++;
          ans.PB('S');
          c--;
        }else{
          ans.PB('.');
        }
      }else{
        if(a>0){
          win++;
          ans.PB('R');
          a--;
        }else{
          ans.PB('.');
        }
      }
    }

    if(win*2<n){
      cout<<"NO"<<endl;
    }else{
      cout<<"YES"<<endl;
      rep(i,n){
        if(ans[i]=='.'){
          if(a>0){
            cout<<'R';
            a--;
          }else if(b>0){
            cout<<'P';
            b--;
          }else{
            cout<<'S';
            c--;
          }
        }else{
          cout<<ans[i];
        }
      }
      cout<<endl;
    }
  }


}

