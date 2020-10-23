

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

    int n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(all(a));

    int l=-(INF>>1),r=(INF>>1);

    while(r-l>1){
        int m=(l+r)/2;
        int s=0,t=0;
        rep(i,n){
            if(a[i]>0){
                int l2=-1,r2=n;
                while(r2-l2>1){
                    int m2=(l2+r2)/2;
                    if(a[i]*a[m2]<=m) l2=m2;
                    else r2=m2;
                }
                s+= r2;
            }else if(a[i]<0){
                int l2=-1,r2=n;
                while(r2-l2>1){
                    int m2=(l2+r2)/2;
                    if(a[i]*a[m2]<=m) r2=m2;
                    else l2=m2;
                }
                s+= n-r2;
            }else if(m>=0) s+=n;
            if(a[i]*a[i]<=m) t++;
        }
        //cout<<l<<' '<<r<<endl;
        int num=(s-t)/2;
        if(num>=k) r=m;
        else l=m;
    }

    cout<<r<<endl;


}
