
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



int n,a,b,c,d;
string s;
bool ans1,ans2;

void f(int x,int g,bool fl[]){
  //cout<<x<<' '<<g<<endl;
  if(x>=n||s[x]=='#'||fl[x]) return;
  fl[x]=true;
  
  if(x==g){
    //cout<<g<<endl;
    if(g==c) ans1=true;
    else ans2=true;
    s[g]='#';
    return;
  }

  f(x+2,g,fl);
  f(x+1,g,fl);
}



main(){
  cin>>n>>a>>b>>c>>d;
  cin>>s;
  a--;
  b--;
  c--;
  d--;

  bool h[210000]={};
  bool g[210000]={};

  s[a]='#';
  f(b,d,h);
  s[a]='.';
  f(a,c,g);
  if(ans1&&ans2){
    cout<<"Yes"<<endl;
    return 0;
  }

  s[a]='.';
  s[b]='#';
  s[c]='.';
  s[d]='.';
  ans1=false;
  ans2=false;
  bool r[2100000]={};
  bool t[2100000]={};
  f(a,c,r);
  s[b]='.';
  f(b,d,t);
  if(ans1&&ans2){
    cout<<"Yes"<<endl;
    return 0;
  }
  s[a]='.';
  s[b]='.';
  s[c]='.';
  s[d]='.';

  for(int i=max(a,b);i<min(n-2,min(c,d));i++){
    if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
      cout<<"Yes"<<endl;
      return 0;
    }
  }

  cout<<"No"<<endl;


}
