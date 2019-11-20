

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }

  set<int> s;
  rep(i,n){
    if(a[i]>0){
      if(s.find(a[i])!=s.end()){
        cout<<-1<<endl;
        return 0;
      }else{
        s.insert(a[i]);
      }
    }else{
      if(s.find(-a[i])==s.end()){
        cout<<-1<<endl;
        return 0;
      }else{
        s.erase(-a[i]);
      }
    }
  }

  if(s.size()){
    cout<<-1<<endl;
    return 0;
  }

  
  
  vi ans;
  int j=-1;
  rep(i,n){
    if(a[i]>0){
      s.insert(a[i]);
    }else{
      s.erase(-a[i]);
      if(s.empty()){
        ans.PB(i-j);
        j=i;
      }
    }
  }

  int sum=0;
  rep(i,ans.size()){
    set<int> s;
    FOR(j,sum,sum+ans[i]){
      if(s.find(a[j])!=s.end()){
        cout<<-1<<endl;
        return 0;
      }
      s.insert(a[j]);
    }
    sum+=ans[i];
  }

  cout<<ans.size()<<endl;
  for(int x:ans){
    cout<<x<<' ';
  }
  cout<<endl;
 
}
