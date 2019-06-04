
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



string s;

main(){
  cin>>s;
  int n=s.size();
  int ans=0;
  int suma=0;

  int i=0;
  while(i<n){
    if(i<n-2&&s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
      ans++;
      ans+=suma;
      suma++;
      int sum=1;
      int j=i+3;
      while(true){
        if(j+2<n&&s[j]=='A'&&s[j+1]=='B'&&s[j+2]=='C'){
          suma++;
          ans+=suma;
          j+=3;
        }else break;
      }
      i=j;

    }else if(s[i]=='A'){
      suma++;
      i++;
    }else if(i<n-1&&s[i]=='B'&&s[i+1]=='C'&&suma>0){
      ans+=suma; 
      i+=2;
    }else{
      suma=0;
      i++;
    }
    //cout<<i<<' '<<ans<<endl;
  }

  cout<<ans<<endl;

}
