
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
int a[200000];
int ans=0;
int c[100010];
set<int> s[100010];


main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  rep(i,n){
    if(a[i]!=a[0]) break;
    ans=i+1;
  }

  map<int,bool> m;
  rep(i,n){
    if(m[a[i]]) break;
    m[a[i]]=true;
    ans=max(ans,i+1);
  }

  
  int ma=0;

  rep(i,n){
    s[c[a[i]]+1].insert(a[i]);
    s[c[a[i]]].erase(a[i]);
    c[a[i]]++;
    ma=max(ma,c[a[i]]);
    if(s[ma].size()==1&&s[ma-1].size()*(ma-1)==i-(ma-1)){
      ans=max(ans,i+1);
    }else if(s[ma].size()*ma==i&&s[1].size()==1){
      ans=max(ans,i+1);
    }
  }

  cout<<ans<<endl;
}
