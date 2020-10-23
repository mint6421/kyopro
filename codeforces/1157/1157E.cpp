
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



int n,k;


main(){
  cin>>n>>k;
  double kn=k;
  int kk,m=0;

  /*
  while(m<n){
    m=(2*kk-k+1)*(kn/2);
    cout<<m<<endl;
    kk++;
  }
   */
  

  kk=(n+k-1)/k;
  kk-=(k/2);
  m=(2*kk+k-1)*(kn/2);
  
  if(m-n<0){
    kk++;
    m=(2*kk+k-1)*(kn/2);
  }
  //cout<<kk<<' '<<m<<endl;


  vector<int> ans;
  FOR(i,kk,kk+k+1){
    ans.PB(i);
    //cout<<i<<endl;
  }
 
  int sum=0;
  //cout<<m-n<<' '<<kk<<endl;
  if(m-n>=k){
    cout<<"NO"<<endl;
    return 0;
  }
  
  rep(i,m-n){
    ans[i]--;
    sum++;
  }

  if(sum==1){
    ans[1]--;
    ans[k-1]++;
  }

 
  rep(i,k-1){
    if(2*ans[i]<ans[i+1]){
      cout<<"NO"<<endl;
      return 0;
    }
  }

  cout<<"YES"<<endl;
  rep(i,k){
    cout<<ans[i]<<' ';
  }
  cout<<endl;

}
