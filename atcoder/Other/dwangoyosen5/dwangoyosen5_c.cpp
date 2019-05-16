
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
string s;
int q;
int mc[1100000];

main(){
  cin>>n;
  cin>>s;
  cin>>q;

  while(q--){
    int k;
    cin>>k;
    int d=0,m=0,dm=0;
    int ans=0;

    rep(i,n){
      if(s[i]=='D'){
        d++;
      }else if(s[i]=='M'){
        m++;
        dm+=d;
      }else if(s[i]=='C'){
        ans+=dm;
      }

      if(i>=k-1){
        int j=i-k+1;
        if(s[j]=='D'){
          d--;
          dm-=m;
        }else if(s[j]=='M'){
          m--;
        }
      }
    }    
    cout<<ans<<endl;
  }

}
