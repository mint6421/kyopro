
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



int contain(string a, string b){
    int ret = 0;
    int al = a.length(), bl = b.length();
    if(al > bl) return 0;

    ull t = 1;
    for (int i = 0; i < al; ++i) t *= M;

    ull ah = 0, bh = 0;
    for (int i = 0; i < al; ++i) ah = ah * M + a[i];
    for (int i = 0; i < al; ++i) bh = bh * M + b[i];

    for (int i = 0; i + al <= bl; ++i){
        if(ah == bh) ret++;
        if(i + al < bl) bh = bh * M + b[i + al] - b[i] * t;
    }
    return ret;
}


main(){
  string s;
  int m,ans=0;
  cin>>s;
  cin>>m;
  rep(i,m){
    string t;
    cin>>t;
    ans+=contain(t,s);
  }

  cout<<ans<<endl;
}
