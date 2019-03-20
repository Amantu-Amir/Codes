#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int> adj[mx];
int ids[mx], low[mx], vis[mx], Time, ap[mx], child;
void dfs(int root, int u, int p)
{
	if(p==root) child++;
	vis[u] = 1;
	Time++;
	low[u] = ids[u] = Time;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v==p) continue;
		if(vis[v])
			low[u]= min(low[u], ids[v]);
		else{
			dfs(root, v, u);
			low[u] = min(low[u], low[v]);
			if(ids[u] <= low[v])
				ap[u] = 1;
		}
	}
}
void findArticulationPoint(int n)
{
	//memset(ids, 0, sizeof ids);
	//memset(low, 0, sizeof low);
	memset(ap, 0, sizeof ap);
	Time = 0;
	for(int i=1; i<=n; i++){
		if(vis[i]==0){
			child = 0;
			dfs(i, i, -1);
			ap[i] = (child>1);
		}
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
	findArticulationPoint(n);
	cout<<"Articulation Point at: "<<endl;
	for(int i=1; i<=n; i++){
		if(ap[i]) cout<<"->> "<<i<<endl;
	}
}