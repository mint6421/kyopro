

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



template< typename T >
struct BIT {
  vector< T > data;

  BIT(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret+=data[k];
    return (ret);
  }

  T get(int x,int y){

    return sum(y)-sum(x);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k]+=x;
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    vi p(n);
    rep(i,n){
      cin>>p[i];
    }
    sort(all(p));
    P x,y;
    cin>>x.F>>x.S;
    cin>>y.F>>y.S;
    if(x<y) swap(x,y);
    int k;
    cin>>k;

    int cntx=0,cnty=0,cntxy=0;
    BIT<int> bit(n+1);
    int i=0,j=n-1; 
    int c=1;
    int cnt=1;
    int ans=-1;
    while(c<=n){
      if(c%x.S==0||c%y.S==0){
        bit.add(cnt,p[j]);
        cnt++;
        j--;
        if(c%x.S==0&&c%y.S==0){
          cntxy++;
        }else if(c%x.S==0){
          cntx++;
        }else{
          cnty++;
        }
        int sum=0;
        sum+=(bit.sum(cntxy)/100)*(x.F+y.F);
        sum+=((bit.sum(cntxy+cntx)-bit.sum(cntxy))/100)*(x.F);
        sum+=((bit.sum(cntxy+cntx+cnty)-bit.sum(cntxy+cntx))/100)*(y.F);
        //cout<<bit.sum(cntxy)<<' '<<bit.sum(cntxy+cntx)<<' '<<bit.sum(cntxy+cntx+cnty)<<endl;
        //cout<<cntxy<<' '<<cntx<<' '<<cnty<<' '<<sum<<endl;
        if(sum>=k){
          ans=c;
          break;
        }
      }else{
        i++;
      }
      c++;
    }

    cout<<ans<<endl;

  }


}
