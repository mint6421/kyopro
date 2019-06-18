
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


main(){
  int w,h,n;
  cin>>w>>h>>n;
  vector<P> a;

  rep(i,n){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;

    if(y1&&y1!=h&&x1&&x1!=w) continue;
    if(y2&&y2!=h&&x2&&x2!=w) continue;

    if(y1==0){
      a.PB(P(x1,i));
    }else if(x1==w){
      a.PB(P(w+y1,i));
    }else if(y1==h){
      a.PB(P(2*w+h-x1,i));
    }else if(x1==0){
      a.PB(P(2*(w+h)-y1,i));
    }

    x1=x2;
    y1=y2;


    if(y1==0){
      a.PB(P(x1,i));
    }else if(x1==w){
      a.PB(P(w+y1,i));
    }else if(y1==h){
      a.PB(P(2*w+h-x1,i));
    }else if(x1==0){
      a.PB(P(2*(w+h)-y1,i));
    }


  }

  sort(all(a));


  stack<int> st;
  for(auto e:a){
    int p=e.S;
    if(!st.empty()&&st.top()==p){
      st.pop();
    }else{
      st.push(p);
    }
  }

  cout<<(st.empty()?"YES":"NO")<<endl;
}
      
