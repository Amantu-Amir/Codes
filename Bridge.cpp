#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int> adj[mx];
int ids[mx], low[mx], vis[mx], Time;
vector<int> bridges;
void dfs(int u, int p)
{
	vis[u] = 1;
	Time++;
	low[u] = ids[u] = Time;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v==p) continue;
		if(vis[v])
			low[u]= min(low[u], ids[v]);
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(ids[u] < low[v]){
				bridges.push_back(u);
				bridges.push_back(v);
			}
		}
	}
}
void findBridges(int n)
{
	bridges.clear();
	//memset(ids, 0, sizeof ids);
	//memset(low, 0, sizeof low);
	Time = 0;
	for(int i=1; i<=n; i++){
		if(vis[i]==0)
			dfs(i, -1);
	}
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1; i<=n; i++) adj[i].clear();
	while(m--){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<"Bridges at: "<<endl;
	for(int i=0; i<bridges.size(); i+=2){
		cout<<bridges[i]<<" ---- "<<bridges[i+1]<<endl;
	}
}