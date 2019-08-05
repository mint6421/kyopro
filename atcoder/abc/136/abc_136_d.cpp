
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
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin>>s;
  int n=s.size();

  vector<int> v(n,0);

  int i=0;
  while(i<n){
    int j=i;
    if(s[j]=='L'){
      i++;
      continue;
    }
    while(j<n&&s[j]=='R') j++;
    v[j]+=(j-i)/2;
    v[j-1]+=(j-i+1)/2;
    i=j;
  }
  

  i=n-1;
  while(i>=0){
    int j=i;
    if(s[j]=='R'){
      i--;
      continue;
    }
    while(j>=0&&s[j]=='L') j--;
    v[j]+=(i-j)/2;
    v[j+1]+=(i-j+1)/2;
    i=j;
  }

  rep(i,n){
    cout<<v[i]<<' ';
  }
  cout<<endl;



}
