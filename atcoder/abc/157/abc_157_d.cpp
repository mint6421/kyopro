

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



struct UnionFind {
    vector< int > data;

    UnionFind(int sz) {
        data.assign(sz, -1);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k) {
        return (-data[find(k)]);
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    int n,m,k;
    cin>>n>>m>>k;
    
    UnionFind uf(n);
    map<int,int> mp;

    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        uf.unite(a,b);
        mp[a]++;
        mp[b]++;
    }

    rep(i,k){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(uf.find(a)==uf.find(b)){
            mp[a]++;
            mp[b]++;
        }
    }

    rep(i,n){
        if(i) cout<<' ';
        cout<<uf.size(i)-mp[i]-1;
    }
    cout<<endl;


}
