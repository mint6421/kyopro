#include<iostream>
using namespace std;

int f(int m){
  int sum=0;
  while(m){
    sum+=m%10;
    m/=10;
  }
  return sum;
}

int main(){
  int n,a,b;
  cin>>n>>a>>b;

  int ans=0;
  for(int i=1;i<=n;i++){
    int c=f(i);
    if(a<=c&&c<=b)
      ans+=i;
  }

  cout<<ans<<endl;
}

