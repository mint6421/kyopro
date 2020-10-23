
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



main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  int ans=1;
  map<int,int> mp;

  rep(i,n){

    mp[a[i]-1]++; 
    vector<int> b(10);
    rep(j,10){
      b[j]=mp[j];
    }

    sort(all(b));
    reverse(all(b));
    if(b[1]==0)
      ans=i+1;

    int s=1;
    int t=0;
    int u=0;
    rep(j,10){
      if(b[j]!=0&&b[j]!=b[s])
        t++;
      if(b[j]==1) u++;
    }
   
    if(t==1&&(b[0]-b[1]==1||u==1)||t==0&&u==i+1)
      ans=i+1;



  }




  cout<<ans<<endl;
}
