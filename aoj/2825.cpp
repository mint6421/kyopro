#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>


void f(int n,int m){
  vector<P> big(n),small(n);

  for(int i=0;i<n;i++){
    big[i]=P(0,i);
    small[i]=P(0,i);
  }

  for(int i=0;i<m;i++){
    int s,k;
    cin>>s>>k;
    for(int j=0;j<k;j++){
      int x;
      cin>>x;
      x--;
      big[x].first+=s;
      if(k==1) small[x].first+=s;
    }
  }

  sort(big.begin(),big.end());
  reverse(big.begin(),big.end());
  sort(small.begin(),small.end());

  if(big[0].second!=small[0].second){
    cout<<big[0].first-small[0].first+1<<endl;
  }else{
    int ans=big[0].first-small[1].first;
    ans = max(ans,big[1].first-small[0].first);
    cout<<ans+1<<endl;
  }
}

main(){
  int n,m;
  while(true){
    cin>>n>>m;
    if(n==0) break;
    f(n,m);
  }

}
