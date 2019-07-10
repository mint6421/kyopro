#include<bits/stdc++.h>
using namespace std;


void f(int t,int d,int l){
  int ans=0,c=0;

  while(t--){
    int x;
    cin>>x;
    if(t==0) break;
    if(x>=l){
      c=d;
    }else{
      c=max(0,c-1);
    }
    if(c>0){
      ans++;
    }
  }

  cout<<ans<<endl;
}


main(){
  int t,d,l;
  while(true){
    cin>>t>>d>>l;
    if(t==0) break;
    f(t,d,l);
  }

}
