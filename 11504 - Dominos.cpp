#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[100010];
bool visited[100010];
stack <int> pilha;

void buildpilha(int node)
{
	visited[node] = true;
	
	for(int i=0;i<adjlist[node].size();i++)
	{
		int v = adjlist[node][i];
		if(!visited[v])
		{
			buildpilha(v);
		}
	}
	pilha.push(node);
}

void dfs(int node)
{
	visited[node] = true;
	
	for(int i=0;i<adjlist[node].size();i++)
	{
		int v = adjlist[node][i];
		if(!visited[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	int N,M;
	
	int c;
	cin>>c;
	while(c--)
	{
		cin>>N>>M;
		for(int i=1;i<=N;i++) visited[i] = false; 
		for(int i=1;i<=N;i++) adjlist[i].clear();
		for(int i=0;i<M;i++)
		{
			int x,y;
			cin>>x>>y;
			adjlist[x].push_back(y);
		}
		
		
		for(int i=1;i<=N;i++)
		{
			if(!visited[i])
				buildpilha(i);
		}
		
		for(int i=1;i<=N;i++) visited[i] = false; 
		
		int cont = 0;
		
		while(pilha.size())
		{
			if(!visited[pilha.top()])
			{
				cont++;
				dfs(pilha.top());
			}
			pilha.pop();
		}
		
		cout<<cont<<endl;
	}
}
