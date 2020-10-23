

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

    int a[3][3];
    rep(i,3){
        rep(j,3){
            cin>>a[i][j];
        }
    }

    int n;
    cin>>n;
    rep(_,n){
        int b;
        cin>>b;
        rep(i,3){
            rep(j,3){
                if(a[i][j]==b) a[i][j]=-1;
            }
        }
    }

    bool flag=false;

    rep(i,3){
        flag|=(a[i][0]==a[i][1]&&a[i][1]==a[i][2]);
    }

    rep(j,3){
        flag|=(a[0][j]==a[1][j]&&a[1][j]==a[2][j]);
    }

    flag|=(a[0][0]==a[1][1]&&a[1][1]==a[2][2]);
    flag|=(a[0][2]==a[1][1]&&a[1][1]==a[2][0]);

    Yes(flag);


}
