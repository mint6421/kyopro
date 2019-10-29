
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,a;
  string k;
  cin>>n>>a;
  a--;
  cin>>k;
  vi b(n);
  rep(i,n){
    cin>>b[i];
    b[i]--;
  }

  bool d[110000]={};
  int aa=a;

  while(!d[aa]){
    d[aa]=true;
    aa=b[aa];
  }

  int s=aa,c=0;
  while(true){
    aa=b[aa];
    c++;
    if(s==aa) break;
  }
  
  int l=0;
  rep(i,k.size()){
    l*=10;
    l+=k[i]-'0';
    l%=c;
  }

  l=l+((c+n)/c)*c;
  int ans=a;

  if(k.size()<=6) l=stoi(k);

  rep(i,l){
    ans=b[ans];
  }
  
  cout<<ans+1<<endl;



}
