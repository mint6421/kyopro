

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi v;
  map<char,int> mp;
  mp['D']=100;
  mp['C']=200;
  mp['H']=300;
  mp['S']=400;
  mp['A']=1;
  mp['T']=10;
  mp['J']=11;
  mp['Q']=12;
  mp['K']=13;
  FOR(i,2,10){
    mp['0'+i]=i;
  }
  rep(i,n){
    string s;
    cin>>s;
    int m=0;
    m+=mp[s[0]];
    m+=mp[s[1]];
    v.PB(m);
    
  }
  map<int,char> mp1;
  for(auto m:mp){
    //cout<<m.F<<' '<<m.S<<endl;
    mp1[m.S]=m.F;
  }
  sort(all(v));
  rep(i,n){
    if(i) cout<<' ';
    cout<<mp1[v[i]-v[i]%100]<<mp1[v[i]%100];
  }
  cout<<endl;

}
