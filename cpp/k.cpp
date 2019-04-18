#include<iostream>
using namespace std;


int main(){
  int n;
  int t0=0,x0=0,y0=0;

  bool ans=true;
  cin>>n;
  for(int i=0;i<n;i++){
    int t,x,y;
    cin>>t>>x>>y;
    if((t-t0)<abs(x-x0)+abs(y-y0)||(t-t0)%2!=abs(x+y-x0-y0)%2)
      ans = false;
    t0=t;
    x0=x;
    y0=y;
  }

  if(ans)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

}

