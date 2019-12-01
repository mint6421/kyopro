

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}


int comb(int n,int c){
  const int num=400001;
  static int fact[num+1],factr[num+1],inv[num+1];
  if(fact[0]==0){
    inv[1]=fact[0]=factr[0]=1;
    FOR(i,2,num+1) inv[i]=inv[M%i]*(M-M/i)%M;
    FOR(i,1,num+1) fact[i]=fact[i-1]*i%M,factr[i]=factr[i-1]*inv[i]%M;
  }
  if(c<0||c>n) return 0;
  return factr[c]*fact[n]%M*factr[n-c]%M;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int a,b,c;
  cin>>a>>b>>c;
  int d=a+b+c;

  int p[d+10];
  p[0]=1;
  rep(i,d){
    p[i+1]=Mmul(p[i],2);
  }

  int ans=0;
  FOR(i,1,d-1){
    //cout<<i<<endl;
    int res=Mmul(comb(i-1,c-1),Mmul(comb(i-c,b-1),p[i]-1)); 
    ans=Madd(ans,res);
  }

  cout<<ans<<endl;


}
