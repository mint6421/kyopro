
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)573
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

int c[1100][1100];


void comb_table(void){
  for(int i=0;i<=1000;i++){
    for(int j=0;j<=i;j++){
      if(j==0||j==i){
        c[i][j] = 1LL;
      }
      else{
        c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
      }
    }
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  comb_table();

  string s;
  cin>>s;

  map<char,int> mp;
  for(auto c:s){
    mp[c]++;
  }

  int ans=1;
  int n=s.size();

  for(auto e:mp){
    ans*=c[n][e.S];
    ans%=M;
    n-=e.S;
  }

  cout<<(ans-1+M)%M<<endl;

}
