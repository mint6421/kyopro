

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

    int n;
    cin>>n;

    map<int,int> mp;

    FOR(i,1,n+1){
        if(i%10==0) continue;
        int j=i;
        int a=i%10;
        int b=0;
        int c=-1;
        int ji=j;
        while(ji){
            b=ji%10;
            ji/=10;
            c++;
        }
        mp[10*a+b]++;
    }

    int ans=0;
    for(auto m:mp){
        //cout<<m.F<<' '<<m.S<<endl;
        ans+=m.S*mp[m.F/10+(m.F%10)*10];
    }
 

    cout<<ans<<endl;


}
