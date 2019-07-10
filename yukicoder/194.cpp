
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

int n,k;
int a[1100];

#define mat vector<vector<int>> 

mat mul_mat(mat &a, mat &b){
  mat res(a.size(), vector<int>(b[0].size(),0));
  rep(i, a.size())rep(k, b.size())rep(j, b[0].size()){
    res[i][j] = (res[i][j] + (a[i][k] * b[k][j])%M)%M;
  }
  return res;
}
mat power_mat(mat &a,int k){
  mat res(a.size(), vector<int>(a.size()));
  rep(i, a.size()) res[i][i] = 1;
  while(k > 0){
    if(k&1) res = mul_mat(res,a);
    a = mul_mat(a,a);
    k >>= 1;
  }
  return res;
}


int f[1100000];

void solve1(){
  
  
  int sum=0,ans=0;
  rep(i,n){

    f[i]=a[i];
    sum+=f[i];
    sum%=M;
    ans+=f[i];
    ans%=M;
  }

  FOR(i,n,k-1){
    int res=sum;
    sum+=(res+M-f[i%n])%M;
    sum%=M;
    f[i%n]=res;
    ans+=res;
    ans%=M;
    
  }


  cout<<sum<<' '<<(ans+sum)%M<<endl;
}

void solve2(){
  mat s(n,vector<int>(n,0));
  rep(i,n){
    s[i][0]=1;
  }
  rep(i,n-1){
    s[i][i+1]=1;
  }
  mat t(2*n,vector<int>(2*n,0));
  rep(i,n){
    rep(j,n){
      t[i][j]=s[i][j];
      if(i==j){
        t[i+n][i]=1;
        t[i+n][i+n]=1;
      }
    }
  }
 
  s = power_mat(s,k-n);
  int res=0;
  rep(i,n){
    res+=(a[n-1-i]*s[i][0])%M;
    res%=M;
  }

  
  t = power_mat(t,k-n+1);
  t[n][0]--;
  int ans=0;

  rep(i,n){
    ans+=(a[n-1-i]*t[i+n][0])%M;
    ans%=M;
    ans+=a[i];
    ans%=M;
  }

  cout<<res<<' '<<ans<<endl;
  
}

main(){
  cin>>n>>k;
  rep(i,n){
    cin>>a[i];
  
  }

  if(k<=1000000) solve1();
  else solve2();

}
