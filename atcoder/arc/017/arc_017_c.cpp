
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

int n,x;
map<int,int> mp1,mp2;
vi v1,v2;

void f(int bit){
  if(bit>=(1<<(n/2))) return;
  int s1=0;
  rep(i,20){
    if(bit&(1<<i)){
      s1+=v1[i]; 
    }
  }

  mp1[s1]++;
  
  f(bit+1);
}


void g(int bit){
  if(bit>=(1<<((n+1)/2))) return;
  
  int s2=0;
  rep(i,20){
    if(bit&(1<<i)){    
      s2+=v2[i];
    }
  }
  mp2[s2]++;
  g(bit+1);
}




signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>x; 
  rep(i,n){
    int w;
    cin>>w;
    if(i<n/2) v1.PB(w);
    else v2.PB(w);
  }

  f(0);
  g(0);
  int ans=0;
  for(P m:mp1){
    int a=m.F;
    //cout<<m.F<<' '<<m.S<<endl;
    //cout<<"  "<<x-a<<' '<<mp2[x-a]<<endl;
    ans+=m.S*mp2[x-a];
  }

  cout<<ans<<endl;
  
}
