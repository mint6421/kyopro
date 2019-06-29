
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


main(){
  int n;
  cin>>n;
  vector<string> s(n);
  rep(i,n){
    cin>>s[i];
  }

  int ans=0;
  int i=0;

  while(i<n){
    int j=i;
    if(s[i][0]!='/'){
      i++;
      continue;
    }
    while(j<n&&s[i]==s[j]) j++;
    int k=j;
    while(k<n&&s[j]==s[k]) k++;
    if(j-i==k-j){
      ans++;
      i=k;
    }else{
      i=j;
    }
  
  }

  cout<<ans<<endl;
}

