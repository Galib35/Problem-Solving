#include<bits/stdc++.h>
using namespace std;

int vis[1000];
int color[1000];
std::vector<int> graph[1000];


bool DFS(int u){

	if(!vis[u])vis[u]=1;


	for(int v: graph[u]){

		if(!vis[v]){
			if(color[u]==1)color[v]=2;
			else color[v]=1;

			if(DFS(v)==false)return false;
		}

		if(vis[v] && color[u]==color[v])return false;
	}

	return true;
}




int main()
{
	int node,edge;
	while(cin>>node){
		if(node==0)break;

		for(int i=0;i<=node;i++){
			graph[i].clear(); vis[i]=0;

		}

		cin>>edge;
		while(edge--){
			int u,v;
			cin>>u>>v;

			graph[u].push_back(v);
			graph[v].push_back(u);

		}

		color[0]=1;

		if(DFS(0))cout<<"BICOLORABLE."<<endl;
		else cout<<"NOT BICOLORABLE."<<endl;
	}
}
