

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k;
  cin>>n>>k;
  vi v;
  set<int> st;
  map<char,int> mp;
  mp['S']=0;
  mp['E']=1;
  mp['T']=2;
  rep(i,n){
    string s;
    cin>>s;
    int res=0;
    rep(i,k){
      res*=3;
      res+=mp[s[i]];
    }
    v.PB(res);
    st.insert(v[i]);
  }

  int ans=0;
  rep(i,n){
    FOR(j,i+1,n){
      int s=v[i],t=v[j];
      //cout<<s<<' '<<t<<endl;
      int res=0;
      int p=pow(3,k-1);
      rep(l,k){
        res*=3;
        int sp=s/p;
        int tp=t/p;
        //cout<<' '<<sp<<' '<<tp<<endl;
        if(sp==tp){
          res+=sp;
        }else{
          res+=3-(sp+tp);
        }
        s%=p;
        t%=p;
        p/=3;
      }
      //cout<<res<<endl;
      ans+=(st.find(res)!=st.end());
    }
  }

  cout<<ans/3<<endl;


}
