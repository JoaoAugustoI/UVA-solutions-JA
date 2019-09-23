#include <bits/stdc++.h>

using namespace std;
int N,root,edgecount,cont;
vector<int> adjlist[110];
int ids[110];
int low[110];
bool visitados[110];
bool isArt[110];

void dfs(int at,int parent,int root)
{
    if(parent == root)
        edgecount++;
    low[at] = ids[at] = ++cont;
    visitados[at] = true;
    for(int to : adjlist[at])
    {
        if(parent == to)
            continue;
        if(!visitados[to])
        {
            dfs(to,at,root);

            low[at] = min(low[at],low[to]);
            if(ids[at]<=low[to])
                isArt[at] = 1;
        }
        else
        {
            low[at] = min(low[at],ids[to]);
        }
    }
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    while(cin>>N and N)
    {
        cin.ignore();
        for(int i=0;i<=N;i++)
        {
            adjlist[i].clear();
        }
        string X;
        while(getline(cin,X) and X!="0")
        {
            stringstream str(X);
            int x,y;
            str>>x;
            while(str>>y)
            {
                adjlist[x].push_back(y);
                adjlist[y].push_back(x);
            }
        }


        for(int i=0;i<=N;i++)
        {
            isArt[i] = visitados[i] = ids[i] = low[i] = 0;
        }
        cont = 0;
        for(int i=1;i<=N;i++)
        {
            if(!visitados[i])
            {
                edgecount = 0;
                dfs(i,-1,i);
                if(edgecount<=1)
                    isArt[i] = false;
                else
                {
                    isArt[i] = true;
                }
            }
        }

        int resp = 0;
        for(int i=1;i<=N;i++)
        {
            if(isArt[i])
            {
                //printf("articulation point: %d\n",i);
                resp++;
            }
        }
        cout<<resp<<endl;
    }
}
