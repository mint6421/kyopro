
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

int a,b;

void f(string s,string t){
  string sa=s;
  string sb=s;
  rep(i,s.size()){
    if(s[i]=='?'){
      sa[i]='a';
      sb[i]='z';
    }
  }

  if(sa>t) a++;
  if(sb<t) b++;
}

int main(){
  string s[11000],t;

  cin>>n;
  rep(i,n){
    cin>>s[i];
  }
  cin>>t;

  rep(i,n){
    f(s[i],t);
  }
  
//  cout<<a<<' '<<b<<endl;
  FOR(i,b+1,n-a+2){
    if(i>b+1) cout<<' ';
    cout<<i;
  }
  cout<<endl;

}
