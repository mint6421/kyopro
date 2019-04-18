

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

int n,k;


char c[300000];
P b[300000];
int l[300000],r[300000];

int main(){
  cin>>n>>k;
  rep(i,n){
    int a;
    cin>>a;
    b[i]=P(a,i);
  }
  rep(i,n){
    r[i]=i+1;
    l[i]=i-1;
  }
  sort(b,b+n);
  reverse(b,b+n);

  int t=0;
  rep(p,n){
    int m=b[p].S;
    if(c[m]!=0) continue;
    c[m]=(t%2)+1;
    int i=m;
    int d=0;
    while(d<k&&i<n){
      if(c[i]==0){
        c[i]=(t%2)+1;
        d++;
      }
      i=r[i];
    }
    int j=m;
    d=0;
    while(d<k&&j>=0){
      if(c[j]==0){
        c[j]=(t%2)+1;
        d++;
      }
      j=l[j];
    }
    r[j]=i;
    l[i]=j;
    t++;
  }

  rep(i,n){
    c[i]+='0';
  }

  cout<<c<<endl;
}
