
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


string f(string s,int k){
  int a[110000]={};
  int b[110000]={};
  rrep(i,k-1){
    a[k-i-1]=s[i]-'0';
  }
  RFOR(i,s.size()-1,k){
    b[s.size()-i-1]=s[i]-'0';
  }
  int c[120000]={};
  rep(i,110000){
    c[i]+=a[i]+b[i];
  
    //cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
    if(c[i]>9){
      c[i]-=10;
      c[i+1]++;
    }
  }

  string t;
  bool flag=false;
  rrep(i,110000){
    if(c[i]>0) flag=true;
    if(flag){
      t+=(c[i]+'0');
    }
  }

  //cout<<t<<endl;
  
  return t;
}


string g(string a,string b){
  if(a.size()>b.size()) return b;
  if(a.size()<b.size()) return a;

  rep(i,a.size()){
    if(a[i]>b[i]) return b;
    if(a[i]<b[i]) return a;
  }

  return a;
}



main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int l=n/2;
  int r=n-l;
  while(s[l]=='0') l--;
  while(s[r]=='0') r++;

  string a=f(s,l);
  string b=f(s,r);


  cout<<g(a,b)<<endl;

}
