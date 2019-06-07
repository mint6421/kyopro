
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

int n;
string s;

main(){
  cin>>s;
  n=s.size();
  rep(i,n){
    if(i==0&&(s[0]=='0'||s[n-2]=='0')){
      cout<<-1<<endl;
      return 0;
    }

    else if(i==n-1&&s[i]=='1'){
      cout<<-1<<endl;
      return 0;
    }
    if(i<n-1&&s[i]!=s[n-i-2]){
      cout<<-1<<endl;
      return 0;
    }
  }

  int a=1,t=3;
  queue<int> q;
  q.push(2);

  rep(i,n-1){
    if(s[i]=='1'){
      while(!q.empty()){
        cout<<a<<' '<<q.front()<<endl;
        if(q.size()==1) a=q.front();
        q.pop();
      }
      q.push(t++);
    }else{
      q.push(t++);
    }
  }

}
