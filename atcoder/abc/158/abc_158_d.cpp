

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
    int q;
    cin>>q;
    bool b=true;
    vector<char> v[2];

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            b=!b;
        }else{
            int f;
            char c;
            cin>>f>>c;
            if(f==1&&b||f==2&&!b){
                v[0].PB(c);
            }else{
                v[1].PB(c);
            }
        }
    }

    if(b){
        rrep(i,v[0].size()-1){
            cout<<v[0][i];
        }
        cout<<s;
        rep(i,v[1].size()){
            cout<<v[1][i];
        }
        cout<<endl;
    }else{
        rrep(i,v[1].size()-1){
            cout<<v[1][i];
        }
        rrep(i,s.size()-1){
            cout<<s[i];
        }
        rep(i,v[0].size()){
            cout<<v[0][i];
        }
        cout<<endl;
    }



}
