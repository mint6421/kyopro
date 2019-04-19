#include<iostream>
#include<algorithm>
using namespace std;

bool f(string s){
  while(!s.empty()){  
    if(s.size()>=5&&s.substr(0,5)=="maerd"){
      s.erase(0,5);
    }
    else if(s.size()>=7&&s.substr(0,7)=="remaerd"){
      s.erase(0,7);
    }
    else if(s.size()>=5&&s.substr(0,5)=="esare"){
      s.erase(0,5);
    }
    else if(s.size()>=6&&s.substr(0,6)=="resare"){
      s.erase(0,6);
    }
    else
      return false;
  }
  return true;
}

int main(){
  string s;
  cin>>s;
  reverse(s.begin(),s.end());

  if(f(s))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}

