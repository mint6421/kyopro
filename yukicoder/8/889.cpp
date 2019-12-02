
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
#define IP pair<int,P>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}

bool f(int n){
  if(n==0||n==1) return false;
  FOR(i,2,n){
    if(n%i==0) return false;
  }
  return true;
}

bool g(int n){
  FOR(i,2,n){
    if(i*i==n) return true;
  }
  return false;
}

bool h(int n){
  FOR(i,2,n){
    if(i*i*i==n) return true;
  }
  return false;
}

bool i(int n){
  if(n==0) return false;
  int s=0;
  FOR(i,1,n){
    if(n%i==0) s+=i;
  }

  return (n==s);
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  int a[5]={};
  if(f(n)){
    a[0]++;
    //cout<<"Sosu!"<<endl;
  }else if(g(n)){
    a[1]++;
    //cout<<"Heihosu!"<<endl;
  }else if(h(n)){
    a[2]++;
    //cout<<"Ripposu!"<<endl;
  }else if(i(n)){
    a[3]++;
    //cout<<"Kanzensu!"<<endl;
  }

  rep(i,4){
    a[i+1]+=a[i];
  }

  if(a[4]!=1){
    cout<<n<<endl;
    return 0;
  }

  rep(i,4){
    if(a[i]){
      if(i==0)cout<<"Sosu!"<<endl;
      if(i==1)cout<<"Heihosu!"<<endl;
      if(i==2)cout<<"Ripposu!"<<endl;
      if(i==3)cout<<"Kanzensu!"<<endl;
      return 0;
    }
  }



}
