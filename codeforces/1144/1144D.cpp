

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

int n;
int ans=0;
ll a[300000];
ll b[300000];

int main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
    b[i]=a[i];
  }

  sort(b,b+n);
  int ii=0,m=-1,mm=-1;
  while(ii<n){
    int j=ii;
    while(j<n&&b[j]==b[ii]) j++;
    if(m<j-ii){
      m=j-ii;
      mm=b[ii];
    }
    ii=j;
  }

  vector<int> v;
  v.PB(-1);
  rep(i,n){
    if(a[i]==mm) v.PB(i);
  }
  

  
  cout<<n-m<<endl;

  FOR(i,1,v.size()){
    int j=v[i]-1;
    int k=v[i];
    while(j>v[i-1]){
      if(a[k]>a[j]){
        cout<<1<<' '<<j+1<<' '<<j+2<<endl;
      }
      else{
        cout<<2<<' '<<j+1<<' '<<j+2<<endl;
      }
      j--;
    }
  }

  int j=v[v.size()-1]+1;
  while(j<n){
    int k=v[v.size()-1];
    if(a[k]>a[j]){
      cout<<1<<' '<<j+1<<' '<<j<<endl;
    }
    else{
      cout<<2<<' '<<j+1<<' '<<j<<endl;
    }
    j++;
  }

}
