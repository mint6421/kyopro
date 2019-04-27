
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}
#define int ll

int n;
int a[300000];

main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  int l=0,r=n-1;
  int t=0;
  int ans=0;
  string s="";

  while(r-l>=0&&(t<a[l]||t<a[r])){
    if(t<a[l]&&t<a[r]){
      if(a[l]<a[r]){
        t=a[l];
        l++;
        ans++;
        s+='L';
      }
      else{
        t=a[r];
        r--;
        ans++;
        s+='R';
      }
    }
    else if(t<a[l]){
      t=a[l];
      l++;
      ans++;
      s+='L';
    }
    else {
      t=a[r];
      r--;
      ans++;
      s+='R';
    }
  }

  cout<<ans<<endl;
  cout<<s<<endl;
}

