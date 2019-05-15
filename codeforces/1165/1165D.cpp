

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
main(){
  init();
  cin>>n;
  while(n--){
    int t;
    cin>>t;
    vector<int> v;
    rep(i,t){
      int a;
      cin>>a;
      v.PB(a);
    }

    sort(all(v));
    int res=v[0]*v[t-1];
    bool flag=true;

    int i=0,j=t-1;
    while(i<=j){
      if(v[i]*v[j]!=res)
        flag=false;
      i++;
      j--;
    }

    for(int i=2;i*i<=res;i++){
      if(res%i==0){
        if(find(all(v),i)==v.end())
          flag=false;
        if(i*i!=res&&find(all(v),res/i)==v.end())
          flag=false;
      }
    }

     
    if(flag)
      cout<<res<<endl;
    else
      cout<<-1<<endl;

  }

}
