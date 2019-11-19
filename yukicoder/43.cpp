

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}

int ans=inf;

void f(int n,string s[],int m){


  if(m==0){

    /*
    rep(i,n){
      cout<<s[i]<<endl;
    }
    */
    vi v;
    rep(i,n){
      int res=0;
      rep(j,n){
        res+=(s[i][j]=='o');
      }
      v.PB(-res);
    }

    set<int> st;
    FOR(i,1,n){
      st.insert(v[i]);
    }
    int res=1;
    for(int x:st){
      //cout<<x<<' '<<v[0]<<endl;
      if(x>=v[0]) break;
      res++;
    }

    ans=min(ans,res);
    return;
  }
    
  rep(i,n){
    rep(j,n){
      if(s[i][j]=='-'){
        //cout<<' '<<i<<' '<<j<<endl;
        s[i][j]='x';
        s[j][i]='o';
        f(n,s,m-2);
        s[i][j]='o';
        s[j][i]='x';
        f(n,s,m-2);
        s[i][j]='-';
        s[j][i]='-';
        return;
      }
    }
  }
}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  string s[10];
  rep(i,n){
    cin>>s[i];
  }

   
   
  int m=0;
  rep(i,n){
    rep(j,n){
      if(s[i][j]=='-') m++;
    }
  }

  

  f(n,s,m);

  cout<<ans<<endl;


}
