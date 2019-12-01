

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
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int t1,t2,a1,a2,b1,b2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
  
  int s1=t1*(a1-b1);
  int s2=t2*(a2-b2);
  if(s1>0){
    s1*=-1;
    s2*=-1;
  }

  if(s1+s2<0){
    cout<<0<<endl;
  }else if(s1+s2==0){
    cout<<"infinity"<<endl;
  }else{
    int s=(-s1)/(s1+s2);
    int t=(-s1)%(s1+s2);
    cout<<2*s+!!t<<endl;
  }


}
