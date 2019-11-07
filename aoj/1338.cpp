
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

vi v[110];
vector<P> res[110];





signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  FOR(H,2,101){
    int bunshi=3600*H;
    int bunbo=120*H-(H+1);
    int g=__gcd(bunshi,bunbo);
    bunshi/=g;
    bunbo/=g;
    int ori_bunshi=bunshi;
    while(bunshi<3600*H*bunbo){
      v[H].PB(bunshi/bunbo);
      res[H].PB(P(bunshi,bunbo));
      bunshi+=ori_bunshi;
    }
  }

  int H,h,m,s;
  while(true){
    cin>>H>>h>>m>>s;
    if(H==0) break;
    int t=3600*h+60*m+s;
    int i=-1;
    auto it = lower_bound(all(v[H]),t);
    if(it==v[H].end()) i=0;
    else i=it-v[H].begin();

    P ans=res[H][i];
    int hour=(ans.F/ans.S)/3600;
    int minits=((ans.F/ans.S)/60)%60;
    int second=((ans.F/ans.S)%60)*ans.S+ans.F%ans.S;
    int bunbo=ans.S;
    cout<<hour<<' '<<minits<<' ';
    
    cout<<second/__gcd(second,bunbo)<<' '<<bunbo/__gcd(second,bunbo)<<endl;
  }


}
