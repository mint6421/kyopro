
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
//#define ll long long
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
int a[300000];
int ans1=0;
string s1;

int f(int l,int r,int t,int ans,string s){

  while(r-l>=0&&(t<a[l]||t<a[r])){
//    cout<<r<<' '<<l<<' '<<t<<endl;
    if(t<a[l]&&t<a[r]){
      if(a[l]<a[r]){
        t=a[l];
        l++;
        ans++;
        s+='L';
      }
      else if(a[l]>a[r]){
        t=a[r];
        r--;
        ans++;
        s+='R';
      }
      else {
        if(f(l,r-1,a[r],ans+1,s+'R')>f(l+1,r,a[l],ans+1,s+'L')){
          t=a[r];
          r--;
          ans++;
          s+='R';
        }
        else{
          t=a[l];
          l++;
          ans++;
          s+='L';
        }
      }
    }
    else if(t<a[l]){
      t=a[l];
      l++;
      ans++;
      s+='L';
    }
    else {
      t=a[r];
      r--;
      ans++;
      s+='R';
    }
  }
/*
  cout<<l<<r<<t<<endl;
  cout<<s<<endl;
  cout<<ans<<endl;
  */
  if(ans1<ans){
    ans1=ans;
    s1=s;
  }
  return ans;
}
main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  f(0,n-1,0,0,"");
  cout<<ans1<<endl;
  cout<<s1<<endl;
}

