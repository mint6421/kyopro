#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define int long long
using namespace std;

vector<int> dijkstra(vector<vector<int>> es,int n,int s){
  
  vector<int> dist(n,LLONG_MAX);
  using Pi = pair<int,int>;
  priority_queue<Pi,vector<Pi>,greater<Pi>> q;
  dist[s] = 0;
  q.emplace(dist[s],s);
  while(!q.empty()){
    int cost;
    int idx;
    tie(cost,idx) = q.top();
    q.pop();
    if(dist[idx] < cost) continue;
    for( auto e : es[idx]){
      auto next_cost = cost + 1;
      if(dist[e] <= next_cost) continue;
      dist[e] = next_cost;
      q.emplace(dist[e],e);
    }
  }
  return dist;
}


main(){
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;

  vector<vector<int>> es(n);

  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    es[x].push_back(y);
    es[y].push_back(x);
  }

  vector<int> sv = dijkstra(es,n,s);
  vector<int> tv = dijkstra(es,n,t);

  int dist = sv[t];
  if(dist==LLONG_MAX){
    cout<<0<<endl;
    return 0;
  }
  sort(all(sv));
  sort(all(tv));
  int ans=0;
//  cout<<dist<<endl;

  for(int i=0;i<dist;i++){
    int d = dist-i-2;
    int res1 = upper_bound(all(sv),i) - lower_bound(all(sv),i);
    int res2 = upper_bound(all(tv),d)- lower_bound(all(tv),d);
    
//    cout<<res1<<' '<<res2<<endl;
    ans+=res1*res2;
  }

  cout<<ans<<endl;
}
