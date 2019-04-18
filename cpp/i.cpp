#include<iostream>
using namespace std;

int main(){
  int n,y;
  cin>>n>>y;
  int a1=-1,a2=-1,a3=-1;

  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1-i;j++){
      int k=n-i-j;
      if(10000*i+5000*j+1000*k==y){
        a1=i;
        a2=j;
        a3=k;
      }
    }
  }

  cout<<a1<<' '<<a2<<' '<<a3<<endl;
}

