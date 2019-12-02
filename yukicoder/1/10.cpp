
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
#define vi vector<int>

int n,t;
int a[100];
bool b[100][100100];

void dfs(int k,int m,string s){
  if(m>t) return;
  if(k==n){
    if(m==t){
      cout<<s<<endl;
      exit(0);
    }
    return;

  }
  if(b[k][m]) return;
  b[k][m]=true;
  s+="+";
  dfs(k+1,m+a[k],s);
  s.erase(s.end()-1);
  s+='*';
  dfs(k+1,m*a[k],s);
}


main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>t;
  rep(i,n){
    cin>>a[i];
  }
  dfs(1,a[0],"");


}



