#include<bits/stdc++.h>
using namespace std;

int n,m;
bool b[3000]={};

int main(){
  cin>>n>>m;
  while(m--){
    int l,r;
    cin>>l>>r;
    for(int i=l;i<r;i++){
      b[i]=true;
    }
  }

  int ans=0;
  for(int i=0;i<n+1;i++){
    if(b[i]) ans+=3;
    else ans++;
  }

  cout<<ans<<endl;
}
