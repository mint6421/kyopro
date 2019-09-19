
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
#define IP pair<int,P>
#define PP pair<P,P>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(all(a));
  bool flag=true;

  if(a[0]!=a[1]){
    if(a[n-1]-a[0]!=a[0]) flag=false;
    FOR(i,1,n){
      int j=i;
      if(a[i]-a[i-1]!=1) flag=false;
      while(j<n&&a[i]==a[j]) j++;
      if(j-i<2) flag=false;
      i=j-1;
    }
  }else{
    if(a[n-1]-a[0]+1!=a[0]) flag=false;
    if(a.size()>2&&a[2]==a[0]) flag=false;
    else{
      FOR(i,2,n){
        int j=i;
        if(a[i]-a[i-1]!=1) flag=false;
        while(j<n&&a[i]==a[j]) j++;
        if(j-i<2) flag=false;
        i=j-1;
      }
    }
  }


  if(flag||n==2&&a[0]==a[1]){
    cout<<"Possible"<<endl;
  }else{
    cout<<"Impossible"<<endl;
  }



}
