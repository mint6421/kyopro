
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



int h,w;


main(){

  cin>>w>>h;
  vector<int> a,b;
 
  rep(i,w){
    int c;
    cin>>c;
    a.PB(c);
  }
 
  rep(i,h){
    int c;
    cin>>c;
    b.PB(c);
  }

  sort(all(a));
  sort(all(b));

  int as=w+1,bs=h+1;
  int ans=0;
  int i=0,j=0;
  rep(_,w+h){
    if(i<a.size()&&j==b.size()||i<a.size()&&a[i]<b[j]){
      ans+=a[i]*bs;
      as--;
      i++;
    }else if(i==a.size()||a[i]>b[j]){
      ans+=b[j]*as;
      bs--;
      j++;
    }else{
      if(as>bs){
        ans+=a[i]*bs;
        as--;
        i++;
      }else{
        ans+=b[j]*as;
        bs--;
        j++;
      }
    }
    //cout<<ans<<' '<<i<<' '<<j<<endl;
  }

  cout<<ans<<endl;
}
