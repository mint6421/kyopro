#include<iostream>
using namespace std;

int f(int a){
  if(a%2) return 0;
  return 1+f(a/2);
}

int main(){
  int n;
  cin>>n;
  int ans=INT8_MAX;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    ans = min(ans,f(a));
  }

  cout<<ans<<endl;
}

