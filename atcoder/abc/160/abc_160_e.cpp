

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

    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vi p(a);
    vi q(b);
    vi r(c);

    rep(i,a){
        cin>>p[i];
    }

    rep(i,b){
        cin>>q[i];
    }

    rep(i,c){
        cin>>r[i];
    }

    sort(all(p));
    reverse(all(p));
    sort(all(q));
    reverse(all(q));
    sort(all(r));
    reverse(all(r));

    int ans=0;
    priority_queue<int,vi,greater<int>> qa,qb;
    rep(i,x){
        ans+=p[i];
        qa.push(p[i]);
    }
    rep(i,y){
        ans+=q[i];
        qb.push(q[i]);
    }

    int itr=0;
    while(itr<c){
        int rs=r[itr];
        if(qa.empty()&&qb.empty()||qa.size()&&qb.size()&&rs<=qa.top()&&rs<=qb.top()) break;

        if(qb.empty()&&rs<=qa.top()||qa.empty()&&rs<=qb.top()) break;

        if(qa.size()&&qb.size()&&rs>=qa.top()&&rs>=qb.top()){
            if(qa.top()>qb.top()){
                ans-=qb.top();
                qb.pop();
                ans+=rs;
            }else{
                ans-=qa.top();
                qa.pop();
                ans+=rs;
            }
        }else if(qb.empty()||qa.size()&&rs>=qa.top()){
            ans-=qa.top();
            qa.pop();
            ans+=rs;
        }else {
            ans-=qb.top();
            qb.pop();
            ans+=rs;
        }
        itr++;
    }


    cout<<ans<<endl;



}
