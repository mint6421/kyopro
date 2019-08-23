
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

  int t;
  cin>>t;
  while(t--){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int ans=n*(a+b)+b;
    int flag=false;
    int i=0;
 
 
    while(i<n){
      int j=i;
      while(j<n&&s[i]==s[j]) j++;
      if(s[i]=='0'){
        if(i==0&&j!=n) flag=true;
        else if(i==0&&j==n);
        else if(j==n) ans+=b;
        else if(b+(j-i)*b+2*a<=(j-i)*b*2){
          //cout<<4342<<endl;
          ans+=b+2*a;
        }else{
          ans+=(j-i)*b;
        }
      }else{
        ans+=(j-i)*b;
      }
      //cout<<i<<' '<<j<<' '<<ans<<endl;
      i=j;
    }
    cout<<ans+flag*a*2<<endl;
  }


}
