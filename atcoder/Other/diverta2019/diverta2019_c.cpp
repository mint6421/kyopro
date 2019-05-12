
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n;
int ans=0;
int a=0,b=0;
int ba=0;

main(){
  cin>>n;
  rep(i,n){
    string s;
    cin>>s;
    
    rep(j,s.size()-1){
      if(s[j]=='A'&&s[j+1]=='B') ans++;
    }
    if(s[0]=='B') b++;
    if(s[s.size()-1]=='A') a++;
    if(s[0]=='B'&&s[s.size()-1]=='A') ba++;
  }
//  cout<<ans<<' '<<a<<' '<<b<<endl;

  if(a>0&&b>0){
    ans+=min(a,b);
  }

  if(ans>0&&a>0&&a==b&&a==ba)
    cout<<ans-1<<endl;
  else
    cout<<ans<<endl;
}
