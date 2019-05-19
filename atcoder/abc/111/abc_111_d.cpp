
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

int n;
vector<P> v;
vector<int> a;


void f(int x,int y){
  rep(i,a.size()){
    if(abs(x)>abs(y)){
      if(x>0){
        x-=a[i];
        cout<<'R';
      }else{
        x+=a[i];
        cout<<'L';
      }
    }else{
      if(y>0){
        y-=a[i];
        cout<<'U';
      }else{
        y+=a[i];
        cout<<'D';
      }
    }
  }
  cout<<endl;
//  cout<<x<<' '<<y<<endl;
}


main(){
  cin>>n;
  rep(i,n){
    int x,y;
    cin>>x>>y;
    v.PB(P(x,y));
  }

  int r=2;
  rep(i,38){
    a.PB(r);
    r*=2;
  }

  int b=(abs(v[0].F)+abs(v[0].S))%2;

  rep(i,n){
    if((abs(v[i].F)+abs(v[i].S))%2!=b){
      cout<<-1<<endl;
      return 0;
    }
  }

  a.PB(1);
  a.PB(1);

  if((abs(v[0].F)+abs(v[0].S))%2)
    a.erase(a.end()-1);

  sort(all(a));
  reverse(all(a));

  cout<<a.size()<<endl;
  rep(i,a.size()){
    if(i)cout<<' ';
    cout<<a[i];
  }
  cout<<endl;

  rep(i,n){
    f(v[i].F,v[i].S);
  }

}

