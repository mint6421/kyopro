

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,h){
      cin>>s[i];
    }



    bool flag1=true;
    rep(i,h){
      rep(j,w){
        flag1&=(s[i][j]=='A');
      }
    }

    if(flag1){
      cout<<0<<endl;
      continue;
    }

    bool flag=false;

    rep(i,h){
      bool flag1=true;
      if(i!=0&&i!=h-1) continue;
      rep(j,w){
        flag1&=(s[i][j]=='A');
      }
      flag|=flag1;
    }

    rep(j,w){
      bool flag1=true;
      if(j!=0&&j!=w-1) continue;
      rep(i,h){
        flag1&=(s[i][j]=='A');
      }
      flag|=flag1;
    }

    if(flag){
      cout<<1<<endl;
      continue;
    }

    if(s[0][0]=='A'||s[0][w-1]=='A'||s[h-1][0]=='A'||s[h-1][w-1]=='A'){
      cout<<2<<endl;
      continue;
    }


    flag=false;
    rep(i,h){
      int cnt=0;
      rep(j,w){
        cnt+=(s[i][j]=='A');
      }
      flag|=(cnt==w);
    }


    rep(j,w){
      int cnt=0;
      rep(i,h){
        cnt+=(s[i][j]=='A');
      }
      flag|=(cnt==h);
    }

    if(flag){
      cout<<2<<endl;
      continue;
    }



    flag=false;

    rep(i,h){
      rep(j,w){
        if(i==0||j==0||i==h-1||j==w-1){
          flag|=(s[i][j]=='A');
        }
      }
    }

    if(flag){
      cout<<3<<endl;
      continue;
    }

    rep(i,h){
      rep(j,w){
        flag|=(s[i][j]=='A');
      }
    }

    if(flag){
      cout<<4<<endl;
      continue;
    }

    cout<<"MORTAL"<<endl;
  }


}
