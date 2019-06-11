
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
#define PC pair<char,string>
#define PS pair<int,PC>
#define PSS pair<string,string>


int n;
vector<PS> v;


main(){
  cin>>n;
  
  rep(i,n){
    string s;
    cin>>s;
    int r=0;
    char c;
    rep(i,s.size()){
      if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'){
        c=s[i];
        r++;
      }
    }
    v.PB(PS(r,PC(c,s)));
  }

  sort(all(v));

  vector<PSS> pf,ps;
  vector<PS> p;

  rep(i,n){

    //cout<<p.size()<<endl;
    if(p.size()&&p[0].F!=v[i].F) p.clear();
    //cout<<v[i].F<<' '<<v[i].S.F<<' '<<v[i+1].S.F<<endl;
    //cout<<p.size()<<endl;
    if(i<n-1&&v[i].F==v[i+1].F){
      if(v[i].S.F==v[i+1].S.F){
        ps.PB(PSS(v[i].S.S,v[i+1].S.S));
        i++;
        continue;
      }
    }

    if(p.size()){
      pf.PB(PSS(p[p.size()-1].S.S,v[i].S.S));
      p.erase(p.end()-1);
    }else{
      p.PB(v[i]);
    }
  }



int ans=min(ps.size(),(pf.size()+ps.size())/2);
  //cout<<pf.size()<<' '<<ps.size()<<endl;
  cout<<ans<<endl;

  rep(i,pf.size()){
    ps.PB(pf[i]);
  }

  int r=ps.size()-1;
  rep(i,ans){
    cout<<ps[r-i].F<<' '<<ps[i].F<<endl;
    cout<<ps[r-i].S<<' '<<ps[i].S<<endl;
  }



}
