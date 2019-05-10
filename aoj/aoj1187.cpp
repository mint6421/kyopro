#include<bits/stdc++.h>
using namespace std;
#define PA pair<PB,int>
#define PB pair<int,int>
#define F first
#define S second

void f(int M,int T,int P,int R){
  int ans[52]={};
  int ptime[52]={};
  int ttime[52][11]={};

  while(R--){
    int m,t,p,j;
    cin>>m>>t>>p>>j;
    if(j==0){
      ans[t]++;
      ptime[t]+=m+ttime[t][p];
    }else{
      ttime[t][p]+=20;
    }
  }

  vector<PA> v;
  for(int i=1;i<T+1;i++){
    v.push_back(PA(PB(P-ans[i],ptime[i]),T-i));
  }
  sort(v.begin(),v.end());

  for(int i=0;i<T-1;i++){
    if(v[i].F.F==v[i+1].F.F&&v[i].F.S==v[i+1].F.S){
      cout<<T-v[i].S<<"=";
    }else{
      cout<<T-v[i].S<<",";
    }
  }
  cout<<T-v[T-1].S<<endl;
}


int main(){

  int M,T,P,R;
  while(true){
    cin>>M>>T>>P>>R;
    if(M==0) break;
    f(M,T,P,R);
  }
}
