

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




struct Combinations {
  static int num;
  vi fact,factr,inv;

  Combinations(int num) {
    
    fact.assign(num+1,0);
    factr.assign(num+1,0);
    inv.assign(num+1,0);
    inv[1]=fact[0]=factr[0]=1;
    FOR(i,2,num+1) inv[i]=inv[M%i]*(M-M/i)%M;
    FOR(i,1,num+1) fact[i]=fact[i-1]*i%M,factr[i]=factr[i-1]*inv[i]%M;
  }


  int comb(int n,int c){
    if(c<0||c>n) return 0;
    return factr[c]*fact[n]%M*factr[n-c]%M;
  }

  int per(int n,int c){
    if(c<0||c>n) return 0;
    return fact[n]*factr[n-c]%M;
  }

  int hcomb(int n,int c){
    if(n==0&&c==0) return 1;
    return comb(n+c-1,c);
  }

};


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  Combinations Comb(2100000);
  while(q--){
    string s;
    cin>>s;
    vi a(2,0);
    int cnt=0;
    rep(i,s.size()){
      if('0'<=s[i]&&s[i]<='9'){
        while('0'<=s[i]&&s[i]<='9'){
          a[cnt]*=10;
          a[cnt]+=s[i]-'0';
          i++;
        }
        cnt++;
      }
    }
    //cout<<a[0]<<' '<<a[1]<<endl;
    if(s[0]=='C') cout<<Comb.comb(a[0],a[1])<<endl;
    if(s[0]=='H') cout<<Comb.hcomb(a[0],a[1])<<endl;
    if(s[0]=='P') cout<<Comb.per(a[0],a[1])<<endl;

  }


}
