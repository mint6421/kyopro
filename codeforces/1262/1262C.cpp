

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    vector<P> res;
    rep(i,n){
      if(i%2==0&&s[i]==')'||i%2&&s[i]=='('){
        int j=i;
        while(s[i]==s[j]) j++;
        res.PB(P(i+1,j+1));
        swap(s[i],s[j]);
      }
    }
    

    rep(i,n){
      if(i%2==0&&s[i]==')'){
        s[i]='(';
        res.PB(P(i+1,i+1));
      }else if(i%2&&s[i]=='('){
        s[i]=')';
        res.PB(P(i+1,i+1));
      }
    }

    //cout<<res.size()<<endl;
    //cout<<s<<endl;
    int kk=n/2;
    for(int i=1;i<=n;i+=2){
      if(kk>k){
        if(s[i]=='(') s[i]=')';
        else s[i]='(';
        if(s[i+1]=='(') s[i+1]=')';
        else s[i+1]='(';
        res.PB(P(i+1,i+2));
        kk--;
      }
    }

    //cout<<s<<endl;

    cout<<res.size()<<endl;
    for(P p:res){
      cout<<p.F<<' '<<p.S<<endl;
    }


  }




}
