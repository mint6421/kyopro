

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

int f(string s,int n,int &i){
  int res=0;
  while(i<n&&'0'<=s[i]&&s[i]<='9'){
    res*=10;
    res+=s[i]-'0';
    i++;
  }

  return res;
}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  string s;
  cin>>s;
  int ans=-INF;
  int n=s.size();
  rep(i,n){
    string t;
    rep(j,n){
      t.PB(s[(i+j)%n]);
    }
    //cout<<t<<endl;
    if(!('0'<=t[0]&&t[0]<='9'&&'0'<=t[n-1]&&t[n-1]<='9')) continue;

    int j=0;
    int sum=0;
    sum=f(t,n,j);
    while(j<n){
       if(t[j]=='+'){
         j++;
         int res=f(t,n,j);
         sum+=res;
       }else{
         j++;
         int res=f(t,n,j);
         sum-=res;
       }
    }
    ans=max(ans,sum);
  }

  cout<<ans<<endl;



}
