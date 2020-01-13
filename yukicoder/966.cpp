

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

int f(int a,int b,int c){
  int res=0;
  if(a>=b){
    res+=a-b+1;
    a=b-1;
  }
  if(a==c){
    a--;
    res++;
  }
  while(c>=b){
    res+=c-b+1;
    c=b-1;
  }
  if(a==c){
    c--;
    res++;
  }
  if(a<=0||c<=0) return inf;

  return res;
}

int g(int a,int b,int c){
  int res=0;
  if(a<=b){
    res=b-a+1;
    b=a-1;
  }

  if(c<=b){
    res+=b-c+1;
    b=c-1;
  }

  if(b<=0) return inf;
  return res;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    if(a==c){
      c--;
      ans++;
    }

    int res=min(f(a,b,c),g(a,b,c));
    if(res==inf){
      cout<<-1<<endl;
      continue;
    }
    
    cout<<ans+res<<endl;
  }


}
