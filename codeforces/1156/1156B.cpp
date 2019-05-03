
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int main(){
  int n;
  cin>>n;
  while(n--){
    string s;
    int m=0;
    cin>>s;
    sort(all(s));
    vector<char> v;
    string ans;
    rep(i,s.size()){
      v.PB(s[i]);
    }
    ans.PB(v[0]);
    v.erase(v.begin());
    while(!v.empty()){
//      cout<<ans<<' '<<v[0]<<endl;
      if(abs(v[0]-ans[ans.size()-1])!=1){
        ans.PB(v[0]);
        v.erase(v.begin());
        m=0;
      }else if(abs(v[0]-ans[0])!=1){
        ans.insert(ans.begin(),v[0]);
        v.erase(v.begin());
        m=0;
      }else{
        v.PB(v[0]);
        v.erase(v.begin());
        m++;
      }
      if(m>v.size()) break;
    }
    
    if(!v.empty()){
      cout<<"No answer"<<endl;
    }else{
      cout<<ans<<endl;
    }
  }
}
