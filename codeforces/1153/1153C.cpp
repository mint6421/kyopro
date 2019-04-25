
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


int main(){
  int n;
  string s;
  int a=0,b=0,c=0;
  cin>>n;
  cin>>s;
  int res=0;
  rep(i,n){
    if(s[i]=='('){
      res++;
    } else if(s[i]==')'){
      res--;
    } else{
      c++;
    }
  }


  a=(c-res)/2;
  b=(c+res)/2;
//  cout<<a<<' '<<b<<endl;

  res=0;

  rep(i,n){
    if(s[i]=='('){
      res++;
    } else if(s[i]==')'){
      res--;
    } else{
      if(a>0){
        s[i]='(';
        a--;
        res++;
      } else{
        s[i]=')';
        b--;
        res--;
      }
    }
//    cout<<a<<' '<<b<<endl;
//    cout<<res<<endl;
    if(i!=n-1&&res<=0){
      cout<<":("<<endl;
      return 0;
    }
  }

  if(res==0&&a==0&&b==0){
    cout<<s<<endl;
  } else{
    cout<<":("<<endl;
  }

  }
