
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
  string s;
  cin>>n;
  cin>>s;
  int l=0,r=0;
  bool b[210000]={};
  rep(i,s.size()){
    if(s[i]=='B'&&(r-l)%2==0||s[i]=='W'&&(r-l)%2){
      r++;
      b[i]=true;
    }else{
      l++;
    }
  }

  if(r!=l){
    cout<<0<<endl;
    return 0;
  }

  /*
  rep(i,s.size()){
    if(b[i]) cout<<'R';
    else cout<<'L';
  }
  cout<<endl;
  */

  int ans=1;
  l=0;
  rrep(i,s.size()-1){
    if(b[i]){
      ans*=l;
      ans%=M;
      l--;
    }else{
      l++;
    }
  }

  FOR(i,2,r+1){
    ans*=i;
    ans%=M;
  }


  cout<<ans<<endl;


}
