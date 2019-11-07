
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
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
#define F first
#define S second
#define PB push_back
#define EB emplace_back
//#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}




class TheBlackJackDivOne{
  

  double f(int s,vi v){
    if(s>=21) return 0;

    double sum=0,res=0;
    FOR(i,2,12) sum+=v[i];
    for(double i=2;i<12;i++){
      if(v[i]){
        v[i]--;
        res+=(1+f(i+s,v))*(v[i]+1)/sum;
        v[i]++;
      }
    }
    return res;
  }


  public:
    double expected(vector<string> cards){
      vi v(12,4);
      
      v[10]=16;
      int s=0;
      
      
      rep(i,cards.size()){
        
        char c=cards[i][0];
        if(c=='J'||c=='Q'||c=='K'||c=='T'){
          v[10]--;
          s+=10;
        }else if(c=='A'){
          v[11]--;
          s+=11;
        }else{
          int k=c-'0';
          s+=k;
          v[k]--;
        }
      }

      return f(s,v);

    }


};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);


  int n;
  cin>>n;
  vector<string> v(n);
  rep(i,n){
    cin>>v[i];
  }
  TheBlackJackDivOne solve;
  cout<<solve.expected(v)<<endl;

}
