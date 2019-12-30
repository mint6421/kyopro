

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi cnt(n+1,0);
  rep(i,n){
    int a;
    cin>>a;
    cnt[a-1]++;
  }

  int ans1=0;
  rep(i,n){
    if(!cnt[i]) continue;
    ans1++;
    i+=2;
  }
  

  int ans2=0;
  int d=2;
  bool r=false;
  rep(i,n){
    if(!cnt[i]){
      d++;
      continue;
    }
    int j=i-1;
    int sum=0;
    while(j+1<n&&cnt[j+1]){
      j++;
      sum+=cnt[j];
    }
    ans2+=(j-i+1);
    if(sum>j-i+1&&(!r||d>1)){
      sum--;
      ans2++;
    }
    r=false;
    if(sum>j-i+1){
      r=true;
      ans2++;
    }
    i=j;
    d=0;
  }

  cout<<ans1<<' '<<ans2<<endl;


}
