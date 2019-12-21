

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

int f(string &s,string &t,int i){
  if(s.size()>t.size()) return 1;
  if(s.size()<t.size()) return -1;
  if(s.size()==i) return 0;

  if(s[i]>t[i]) return 1;
  if(s[i]<t[i]) return -1;

  return f(s,t,i+1);
}
  


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  string sa,pa,xa;
  string sb,pb,xb;
  cin>>sa>>pa>>xa;
  cin>>sb>>pb>>xb;

  int c=f(pa,pb,0);

  if(c==1){
    cout<<sa<<endl;
  }else if(c==-1){
    cout<<sb<<endl;
  }else{
    cout<<-1<<endl;
  }

}
