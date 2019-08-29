#include <bits/stdc++.h>

using namespace std;
vector<int> adjlist[210];
int cor[210];
int N,L;
void coloregrafo(int v)
{
	cor[v] = 0;
    queue <int> kiwi;
    kiwi.push(v);

    while(kiwi.size())
    {
		int x = kiwi.front();
        kiwi.pop();
        for(int i=0;i<adjlist[x].size();i++)
        {
            int u = adjlist[x][i];
            if(cor[u] == -1)
            {
                cor[u] = 1 - cor[x];
                kiwi.push(u);
            }
        }
    }
}

bool bipartido()
{
    for(int i=0;i<N;i++)
    {
        if(cor[i] == -1)
            coloregrafo(i);
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<adjlist[i].size();j++)
        {
            int v = adjlist[i][j];
            if(cor[i] == cor[v])
                return false;
        }
    }
    return true;
}

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>N;
    while(N)
    {
        cin>>L;
        for(int i=0;i<N;i++)
        {
            adjlist[i].clear();
            cor[i] = -1;
        }
        for(int i=0;i<L;i++)
        {
            int x,y;
            cin>>x>>y;
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
        }

        bool flag = bipartido();
        if(flag)
            cout<<"BICOLORABLE."<<endl;
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
        cin>>N;
    }
}
