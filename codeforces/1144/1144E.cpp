
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
string s,t;

main(){
  cin>>n;
  cin>>s>>t;

  int a[200000]={};
  rrep(i,s.size()-1){
    int b=t[i]-s[i];
 
    if(b<0){
      t[i-1]--;
      b+='z'-'a'+1;
    }
    a[i]=b;
  }

  rep(i,s.size()){
//    cout<<a[i]<<endl;
    if(a[i]%2){
      a[i+1]+='z'-'a'+1;
    }
    a[i]/=2;
//    cout<<' '<<a[i]<<endl;
  }

  rrep(i,s.size()-1){
    if(s[i]+a[i]>'z'){
      a[i-1]++;
      s[i]=s[i]+a[i]-('z'-'a'+1);
    }else{
      s[i]+=a[i];
    }
  }

  cout<<s<<endl;


}
