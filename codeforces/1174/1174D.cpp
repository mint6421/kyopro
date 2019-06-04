
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
  int n,x;
  cin>>n>>x;
  vector<int> ans;
  vector<int> res;
  int r;

  for(int i=1;i<(1<<n);i*=2){
    if((x&i)==0){
      ans.PB(i);
      //res.PB(i);
      int k=ans.size()-1;
      rep(j,k){
        ans.PB(ans[j]);
        //res.PB(res[j]);
      }
    }
  }

  for(int i=1;i<(1<<n);i*=2){
   
    //cout<<i<<' '<<(x&i)<<' '<<(x^i)<<endl;
    if((x&i)>(x^i)) continue;
    if(x&i){
      ans.PB(i);
      int k=ans.size()-1;
      rep(j,k){
        ans.PB(ans[j]);
      }
      
     
    }

  }

  cout<<ans.size()<<endl;
  if(ans.empty()) return 0;
  rep(i,ans.size()){
    cout<<ans[i]<<' ';
  }
  cout<<endl;


}
