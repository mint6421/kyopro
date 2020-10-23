

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



template< typename T>
T power(T x,int k){
    T ret=1;
    while(k>0){
        if(k&1) (ret*=x);
        (x*=x); 
        k >>= 1;
    }
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    int h;
    cin>>h;

    int i=power<int>(2,60);

    int ans=0;
    int t=1;
    int c=61;

    while(i>1){
        if(h&i){
            ans+=t;
            t*=2;
            h=h/2;
            //cout<<h<<endl;
            //cout<<t<<endl;
            continue;
        }

        i>>=1;
    }


    cout<<ans+t<<endl;

}
