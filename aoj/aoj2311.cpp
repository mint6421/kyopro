
#include<bits/stdc++.h>
using namespace std;


char s[10][10];
int a[10][10];
int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,1,-1,1,-1};


int g(int y,int x,int b){
  int res=0;

  for(int k=0;k<8;k++){
    int i=y+dy[k],j=x+dx[k];
    //   if(y==4&&x==4) cout<<b<<' '<<i<<"  "<<j<<endl;
    while(0<=j&&j<8&&0<=i&&i<8&&b*a[i][j]==2){
      i+=dy[k];
      j+=dx[k];
    }
    if(0<=j&&j<8&&0<=i&&i<8&&b==a[i][j]){

      res+=max(abs(j-x),abs(i-y))-1;

    }
  }

//  if(x==4&&y==4) cout<<"         "<<res<<endl;
//cout<<x<<"  "<<y<<' '<<res<<endl;
return res;
}



void h(int y,int x,int b){
//  cout<<y<<' '<<x<<endl;
  a[y][x]=b;
  /*
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      cout<<a[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
  */
  for(int k=0;k<8;k++){
    int i=y+dy[k],j=x+dx[k];
    while(0<=j&&j<8&&0<=i&&i<8&&b*a[i][j]==2){
      i+=dy[k];
      j+=dx[k];
    }
    if(0<=j&&j<8&&0<=i&&i<8&&b==a[i][j]){
     
      i=y+dy[k];
      j=x+dx[k];
      while(b*a[i][j]==2){
        a[i][j]=b;
        i+=dy[k];
        j+=dx[k];
      }
    }
  }
 /* 
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      cout<<a[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
  */
}

void f(){

  int c=0;
  int flag=2,flag1=2;
  vector<int> v,w,z;
  while(flag1){
     
    bool hoge=false;
    v.clear();
    w.clear();
    z.clear();
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
    
        if(a[i][j]!=0) continue;
        int res=g(i,j,flag);
        if(res>0){
          hoge=true;
          v.push_back(res);
          w.push_back(i);
          z.push_back(j);
        }
      }
    }
    if(hoge){
//      cout<<v.size()<<endl;
      int resi=-1,resj=-1,s=0;
      for(int i=0;i<v.size();i++){
//        cout<<v[i]<<' '<<w[i]<<' '<<z[i]<<endl;
        if(flag==2&&s<v[i]){
          resi=w[i];
          resj=z[i];
          s=v[i];
        }

        if(flag==1&&s<=v[i]){
          resi=w[i];
          resj=z[i];
          s=v[i];
        }

      }
//      cout<<resi<<' '<<resj<<' '<<s<<endl;
      h(resi,resj,flag);
      flag=(flag==2?1:2);

      flag1=2;
    }
    else{
      flag1--; 
      flag=(flag==2?1:2);
    }
  }
}


int main(){
  for(int i=0;i<8;i++){
    cin>>s[i];
    for(int j=0;j<8;j++){
      if(s[i][j]=='o')
        a[i][j]=2;
      else if(s[i][j]=='x')
        a[i][j]=1;
      else
        a[i][j]=0;
    }
  }

  f();

  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(a[i][j]==2) s[i][j]='o';
      if(a[i][j]==1) s[i][j]='x';
      if(a[i][j]==0) s[i][j]='.';
    }
  }

  for(int i=0;i<8;i++){
    cout<<s[i]<<endl;
  }


}
