
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


string s;
int i;


int f(){
  int res=0;
  bool flag=false;
  if(s[i]=='-'){
    flag=true;
    i++;
  }else if(s[i]=='+'){
    i++;
  }

  while(i<s.size()&&s[i]!='+'&&s[i]!='-'){
    res*=10;
    res+=s[i]-'0';
    i++;
  }

  if(flag) return -res;
  
  return res;
}
  

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>s;

  int ans=f();
 
  while(i<s.size()){
    bool flag=true;
    if(s[i]=='+') flag=false;
    i++;
    int res=f();
    if(flag)
      ans+=res;
    else
      ans-=res;
  }

  cout<<ans<<endl;


}
