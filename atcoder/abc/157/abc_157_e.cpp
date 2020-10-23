

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



template< typename T >
struct BIT {
    vector< T > data;

    BIT (){
        int sz=500000;
        data.assign(++sz, 0);
    }

    T sum(int k) {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret+=data[k];
        return (ret);
    }

    T get(int x,int y){

        return sum(y)-sum(x);
    }

    void add(int k, T x) {
        for(++k; k < data.size(); k += k & -k) data[k]+=x;
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    int n;
    cin>>n;
    string s;
    cin>>s;
    BIT<int> bit[30];
    rep(i,n){
        bit[s[i]-'a'].add(i,1);
    }

    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int i;
            char c;
            cin>>i>>c;
            i--;
            bit[s[i]-'a'].add(i,-1);
            bit[c-'a'].add(i,1);
            s[i]=c;
        }else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            int ans=0;
            rep(i,30){
                //cout<<bit[i].sum(r)<<' '<<bit[i].sum(l)<<endl;
                ans+=(bit[i].get(l-1,r)>0);
            }
            cout<<ans<<endl;
        }
    }


}
