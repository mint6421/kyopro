

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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n;
int a[400000];

int main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  int i=0,j=n-1;

  if(a[i]!=a[j]){
    cout<<n-1<<endl;
  }

  else{
    int ii=0;
    while(a[i]==a[ii]) ii++;
    int jj=n-1;
    while(a[j]==a[jj]) jj--;

    cout<<max(j-ii,jj-i)<<endl;
  }
}
