
#include<bits/stdc++.h>
using namespace std;
#define P pair<int,double>
#define to first
#define cost second
#define PB push_back


void f(int n,int m,int p,int a,int b){
  vector<double> t(n);
  vector<vector<P>> es(m+1);

  for(int i=0;i<n;i++){
    cin>>t[i];
  }
  for(int i=0;i<p;i++){
    int x,y,z;
    cin>>x>>y>>z;
    es[x].PB(P(y,z));
    es[y].PB(P(x,z));
  }
  

  vector<vector<double>> dp(1<<n,vector<double>(m+1,DBL_MAX));

  dp[0][a]=0;


  for(int i=0;i<(1<<n);i++){
    for(int j=1;j<=m;j++){
      if(dp[i][j]==DBL_MAX) continue;
      for(int k=0;k<n;k++){
        if(i&(1<<k)) continue;
        for(auto e:es[j]){
          if(dp[i|(1<<k)][e.to]>dp[i][j]+e.cost/t[k]){
            dp[i|(1<<k)][e.to]=dp[i][j]+e.cost/t[k];
          }
        }
      }
    }
  }


  double ans=DBL_MAX;
  for(int i=0;i<(1<<n);i++)
    ans=min(ans,dp[i][b]);

  if(ans==DBL_MAX){
    cout<<"Impossible"<<endl;
  }else{
    printf("%.10lf\n",(ans==DBL_MAX?-1:ans));
  }
}



int main(){
  int n,m,p,a,b;
  while(true){
    cin>>n>>m>>p>>a>>b;
    if(n==0) break;
    f(n,m,p,a,b);
  }
}
