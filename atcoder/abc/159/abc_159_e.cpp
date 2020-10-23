

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

int h,w,k;
char s[20][2000];
int ans=inf;

void f(int bit,int c){
    int res=c;
    vi cnt(c+1);

    rep(j,w){
        int l=0;
        bool flag=false;
        rep(i,h){
            cnt[l]+=(s[i][j]=='1');
            flag|=(cnt[l]>k);
            if(bit&(1<<i)) l++;
        }
        /*
        if(bit==2){
            cout<<j<<' '<<res<<endl;
            rep(i,c+1){
                cout<<cnt[i]<<' ';
            }
            cout<<endl;
        }
        */
        if(flag){
            res++;
            l=0;
            flag=false;
            rep(i,c+1) cnt[i]=0;
            rep(i,h){
                cnt[l]+=(s[i][j]=='1');
                flag|=(cnt[l]>k);
                if(bit&(1<<i)) l++;
            }
            if(flag) return;
        }
    }
        
    //cout<<bit<<' '<<res<<endl;

    ans=min(ans,res);
}




signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    cin>>h>>w>>k;
    rep(i,h){
        rep(j,w){
            cin>>s[i][j];
        }
    }

    rep(bit,(1<<h)){
        int c=0;
        rep(i,h){
            c+=!!(bit&(1<<i));
        }
        f(bit,c);
    }

    cout<<ans<<endl;


}
