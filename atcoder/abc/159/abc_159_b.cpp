

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

    string s;
    cin>>s;

    int n=s.size();
    bool flag=true;

    rep(i,n){
        flag&=(s[i]==s[n-1-i]);
    }

    string t="";
    rep(i,(n-1)/2){
        t+=s[i];
    }

    int m=t.size();
    rep(i,m){
        flag&=(t[i]==t[m-1-i]);
    }

    string u="";
    FOR(i,(n+3)/2-1,n){
        u+=s[i];
    }

    int l=u.size();
    rep(i,l){
        flag&=(u[i]==u[l-1-i]);
    }

    Yes(flag);



}
