#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int> adj[mx];
int ids[mx], low[mx], vis[mx], Time;
stack<pair<int, int> > st;
void dfs(int root, int u, int par)
{
    int child = 0;
	vis[u] = 1;
	Time++;
	low[u] = ids[u] = Time;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v==par) continue;
		if(vis[v]==0){
            child++;
            st.push({u,v});
			dfs(root, v, u);
			low[u] = min(low[u], low[v]);
			if(par==-1 && child>1){
                cout<<"-> ";
                while(st.top() != make_pair(u,v)){
                    cout<<st.top().first<<" --- "<<st.top().second<<endl;
                    st.pop();
                }
                cout<<st.top().first<<" --- "<<st.top().second<<endl;
                st.pop();
			}
			if(par!=-1 && ids[u] <= low[v]){
			    cout<<"->> ";
			    cout<<st.size()<<endl;
                while(st.top() != make_pair(u,v)){
                    cout<<st.top().first<<" --- "<<st.top().second<<endl;
                    st.pop();
                }
                cout<<st.top().first<<" --- "<<st.top().second<<endl;
                st.pop();
			}
		}
		else if(par!=v && ids[v] < low[u]){
            low[u] = ids[v];
            st.push({u,v});
		}
	}
}
void findBiConnectedComponent(int n)
{
	Time = 0;
	for(int i=0; i<n; i++){
		if(vis[i]==0){
			dfs(i, i, -1);
			cout<<"->>> ";
			while(!st.empty()){
                cout<<st.top().first<<" --- "<<st.top().second<<endl;
                st.pop();
			}
		}
	}
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0; i<n; i++) adj[i].clear();
	while(m--){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	findBiConnectedComponent(n);
}
/// 1308