
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

bool f(string s){
  int a=0,b=0,c=0;
  rep(i,s.size()){
    if(s[i]=='R') a++;
    if(s[i]=='G'){
      if(b>=a){
        return false;
      }
      b++;
    }if(s[i]=='W'){
      if(b==0) return false;
      c=min(b,c+1);
    }
  }

  return (a>0&&a==b&&b==c);

}


main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  while(n--){
    string s;
    cin>>s;
    reverse(all(s));
    if(f(s))
      cout<<"possible"<<endl;
    else
      cout<<"impossible"<<endl;
  }

}



