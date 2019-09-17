#include <bits/stdc++.h>

using namespace std;

map<string,vector<string> > adjlist,transposta;
string inicio;
stack <string> vertices;
map<string,bool> visitados;
bool flag = false;
void buildpilha(string at)
{
    visitados[at] = 1;
    for(int i=0;i<adjlist[at].size();i++)
    {
        string to = adjlist[at][i];
        if(visitados[to] == 0)
        {
            buildpilha(to);
        }
    }
    vertices.push(at);
}

vector <string> impr;
void dfs(string at)
{
    visitados[at] = 1;
    for(int i=0;i<transposta[at].size();i++)
    {
        string to = transposta[at][i];
        if(visitados[to] == 0)
            dfs(to);
    }
    impr.push_back(at);
}


int main()
{
    int N,M;
    bool flag = false;
    cin>>N>>M;
    int i = 1;
    while(N or M)
    {
        string x,y;
        for(int i=0;i<M;i++)
        {
            cin>>x>>y;
            visitados[x] = 0;
            visitados[y] = 0;
            adjlist[x].push_back(y);
            transposta[y].push_back(x);
        }

        for(map<string,vector<string> >::iterator it = adjlist.begin();it!=adjlist.end();it++)
        {
            if(visitados[it->first] == 0)
            {
                buildpilha(it->first);
            }
        }
        adjlist.clear();
        if(flag)
            cout<<endl;
        flag = true;
        printf("Calling circles for data set %d:\n",i++);

        for(map<string,bool>::iterator it = visitados.begin();it!=visitados.end();it++)
            it->second = 0;
        while(vertices.size())
        {
            string v = vertices.top();
            vertices.pop();
            if(visitados[v] == 0)
            {
                dfs(v);
                if(impr.size())
                    cout<<impr[0];
                for(int i=1;i<impr.size();i++)
                {
                    cout<<", "<<impr[i];
                }
                cout<<endl;
                impr.clear();
            }
        }
        transposta.clear();
        visitados.clear();
        cin>>N>>M;
    }
}
