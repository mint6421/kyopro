#include<bits/stdc++.h>
using namespace std;



void f(int n){
  string a;
  map<string,vector<string>> mp;

  for(int j=0;j<n;j++){
    string s;
    string b;
    vector<string> v;
    cin>>s;
    int i=0;
    string t="";
    while(i<s.size()){
      if(s[i]==':'){
        if(j==0)
          a=t;
        b=t;
        t="";
      }
      else if(s[i]==','){
        v.push_back(t);
        t="";
      }
      else if(s[i]=='.'){
        v.push_back(t);
        mp[b]=v;
      }
      else{
        t+=s[i];
      }
      i++;
    }
  }

  int ans=0;
  map<string,bool> ma;
  queue<string> q;
  q.push(a);
  while(!q.empty()){
    string s=q.front();
    q.pop();
    if(ma[s]) continue;
    ma[s]=true;
    if(mp[s].empty()){
//      cout<<s<<endl;
      ans++;
      continue;
    }

    for(string t:mp[s]){
      q.push(t);
    }
  }

  cout<<ans<<endl;


}



int main(){
  int n;
  while(true){
    cin>>n;
    if(!n) break;
    f(n);
  }

}
