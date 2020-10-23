
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

int sum[110000];
vector<int> v[110000];


main(){
  int n;
  cin>>n;
  int e=1;
  e<<=32;
  e--;
  rep(i,100000){
    sum[i]=1;
  }
  int i=0;
  int ans=0;
  
  while(n--){
    string s;
    cin>>s;
    if(s=="add"){
      int res=1;
      rep(j,i+1){
        res*=sum[j];
        if(ans+res>e){
          cout<<"OVERFLOW!!!"<<endl;
          return 0;
        }
      }
      ans+=res;
      if(ans>e){
        cout<<"OVERFLOW!!!"<<endl;
        return 0;
      }
    }else if(s=="end"){
      sum[i]/=v[i][v[i].size()-1];
      v[i].erase(v[i].end()-1);
      if(v[i].empty()){
        i=max(i-1,0LL);
      }
    }else{
      int a;
      cin>>a;
      if(sum[i]>e) i++;
      v[i].PB(a);
      sum[i]*=a;

    }
  }

  cout<<ans<<endl;
}
