
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


int n,m;

main(){
  cin>>n>>m;
  vector<int> a(n),b(m);
  int asum=0,bsum=0;
  int am=-1,an=-1;

  rep(i,n){
    cin>>a[i];
    asum+=a[i];
    if(am<a[i]){
      an=am;
      am=a[i];
    }else if(an<a[i]){
      an=a[i];
    }
  }
  rep(i,m){
    cin>>b[i];
    bsum+=b[i];
  }

  sort(all(a));
  sort(all(b));

  if(am>b[0]){
    cout<<-1<<endl;
  }else if(am==b[0]){
    cout<<asum*m+bsum-am*m<<endl;
  }else{
   
    cout<<asum*m+bsum-am*(m-1)-an<<endl;
  }

}
