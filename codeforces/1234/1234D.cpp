
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




struct BIT{
  vector<int> bit;
  int n;

  BIT(int m){
    n = m;
    bit.assign(2*n,0);
  }

  int sum(int i){
    int s = 0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }
  void add(int i,int x){
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }
};

vector<BIT> bit(30,(int)1e5+10);

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  
  string s;
  cin>>s;
  int n =s.size();

  rep(i,n){
    bit[s[i]-'a'].add(i+1,1);
  }
  

  int q;
  cin>>q;
  while(q--){
    int t;
    cin>>t;
    if(t==1){
      int x;
      cin>>x;
      x--;
      char c;
      cin>>c;
      bit[s[x]-'a'].add(x+1,-1);
      s[x]=c;
      bit[s[x]-'a'].add(x+1,1);
    }else{
      int l,r;
      cin>>l>>r;
      int res=0;
      rep(i,30){
        //cout<<bit[i].sum(r)<<' '<<bit[i].sum(l)<<endl;
        if(bit[i].sum(r)-bit[i].sum(l-1)>0) res++;
      }
      cout<<res<<endl;
    }
  }


}
