#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define F first
#define S second
#define P pair<int,int>
#define PI pair<P,int>
#define all(v) v.begin(),v.end()


void f(int n,int l){
  vector<char> d(n);
  vector<int> p(n);
  rep(i,n){
    cin>>d[i]>>p[i];
  }

  vector<int> sec(n);
  int m=n;
  int s=0;
  while(m){
    //cout<<m<<endl;
    vector<int> next(n);
    rep(i,n){
      if(p[i]==-1||p[i]==0||p[i]==l){
        next[i]=-1;
      }else{
        if(d[i]=='L'){
          next[i]=p[i]-1;
        }else{
          next[i]=p[i]+1;
        }
        if(next[i]==0||next[i]==l){
          m--;
          sec[i]=s+1;
        }
      }
    }
    rep(i,n){
     //cout<<next[i]<<' ';
      FOR(j,i+1,n){
        if(next[i]==-1||next[j]==-1) continue;
        if(next[i]==next[j]){
          d[i]=(d[i]=='L'?'R':'L');
          d[j]=(d[j]=='L'?'R':'L');
        }
      }
    }
    //cout<<endl;
    p=next;
    s++;
  }

  vector<PI> ans(n);
  rep(i,n){
    PI p;
    p.F.F=sec[i];
    p.F.S=(d[i]=='L'?1:0);
    p.S=i;
    ans[i]=p;
    //cout<<p.F.F<<' '<<p.F.S<<' '<<p.S<<endl;
  }
  
  sort(all(ans));
  reverse(all(ans));
  

  cout<<ans[0].F.F<<' '<<ans[0].S+1<<endl;
}



signed main(){

  int n,l;
  while(true){
    cin>>n>>l;
    if(n==0) break;
    f(n,l);
  }
}
