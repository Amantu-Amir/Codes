#include<bits/stdc++.h>
using namespace std;
#define inf 1e18
#define ll long long
#define vi vector<int>
struct HopcroftKarp
{
    int l, r;
    vector<vi> adj;
    vi match;
    vector<ll> dist;
    HopcroftKarp(int _l, int _r)
    {
        l = _l;
        r = _r;
        adj.resize(l+r);
        match.resize(l+r, 0);
        dist.resize(l+r);
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(l+b);
    }
    bool bfs()
    {
        queue<int> q;
        for(int i=1; i<=l; i++){
            if(match[i]==0){
                dist[i] = 0;
                q.push(i);
            }
            else dist[i] = inf;
        }
        dist[0] = inf;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u!=0){
                for(int i=0; i<adj[u].size(); i++){
                    int v = adj[u][i];
                    if(dist[ match[v] ]==inf){
                        dist[match[v]] = dist[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
        }
        return dist[0]!=inf;
    }
    bool dfs(int u)
    {
        if(u!=0){
            for(int i=0; i<adj[u].size(); i++){
                int v = adj[u][i];
                if(dist[ match[v] ] == dist[u]+1){
                    if(dfs(match[v])){
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = inf;
            return false;
        }
        return true;
    }
    int maxMatch()
    {
        int matching = 0;
        while(bfs()){
            for(int i=1; i<=l; i++){
                if(match[i]==0 && dfs(i))
                    matching++;
            }
        }
        return matching;
    }
};
int main()
{
    int n,m,p,a,b;
    scanf("%d%d%d", &n,&m,&p);
    HopcroftKarp hk(n,m);
    while(p--){
        scanf("%d%d", &a, &b);
        hk.addEdge(a,b);
    }
    printf("%d\n", hk.maxMatch());
}
