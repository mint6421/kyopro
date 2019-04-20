
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
int l=1;

bool f(){
  int r=1;

  while(n>=r){
    if(r==n) return false;
    l++;
    r+=l;
  }
  return true;
}

int main(){
  cin>>n;

  if(f()){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;

  int k=l+1;
  int s[500][500]={};
  cout<<k<<endl;
  int t=1;
  rep(i,k){
    int j=0;
    while(j<i){
      s[i][j]=s[j][i-1];
      j++;
    }
    while(j<k){
      s[i][j]=t;
      t++;
      j++;
    }
    t--;
  }

  rep(i,k){
    cout<<k-1<<' ';
    rep(j,k-1){
      cout<<s[i][j]<<' ';
    }
    cout<<endl;
  }
}  
