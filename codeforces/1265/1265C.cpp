

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

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    vi a(n);
    rep(i,n){
      cin>>a[i];
    }
    int m=(n-1)/2;
    while(m>0&&a[m]==a[n/2]) m--;
    int i=0;
    int c[3]={};
    while(i<m&&a[i]==a[0]){
      c[0]++;
      i++;
    }
    while(i<m&&c[0]>=c[1]){
      int j=i;
      while(j<m&&a[i]==a[j]){
        c[1]++;
        j++;
      }
      i=j;
    }

    c[2]=m-i+1;

    if(c[0]<c[1]&&c[0]<c[2])cout<<c[0]<<' '<<c[1]<<' '<<c[2]<<endl;
    else cout<<0<<' '<<0<<' '<<0<<endl;
    
  }


}
