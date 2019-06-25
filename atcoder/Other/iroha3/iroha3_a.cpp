
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



string f(int k){
  if(k==1){
    return "a";
  }if(k==2){
    return "aa";
  }if(k==3){
    return "aaa";
  }if(k==4){
    return "aaai";
  }if(k==5){
    return "aaaji";
  }if(k==6){
    return "aabaji";
  }if(k==7){
    return "agabaji";
  }if(k==8){
    return "dagabaji";
  }

}

void g(int a,int b,int c,int d){
  int res1,res2;
 
  int s=0,t=-1;
  while(s!=c){
    t++;
    int r=t*59;
    r+=a;
    if(r%61==b) s++;
  }
  res1=t*59+a;


  if(abs(res1-6)>=d) res2=6;
  else if(abs(res1-28)>=d) res2=28;
  else if(abs(res1-496)>=d) res2=496;
  else res2=8128;

  cout<<min(res1,res2)<<endl;
  cout<<max(res1,res2)<<endl;
}


int a[30];

main(){
  rep(i,26){
    cin>>a[i];
  }

  cout<<a[0]-a[1]<<endl;
  cout<<a[2]+a[3]<<endl;
  cout<<(a[5]<a[4]?0:a[5]-a[4]+1)<<endl;
  cout<<(a[6]+a[7]+a[8])/3+1<<endl;
  cout<<f(a[9])<<endl;
  g(a[10],a[11],a[12],a[13]);
  cout<<(((a[14]+a[15]+a[16])*(a[17]+a[18]+a[19])%9973)*((a[20]+a[21]+a[22])*(a[23]+a[24]+a[25])%9973))%9973<<endl;

}
