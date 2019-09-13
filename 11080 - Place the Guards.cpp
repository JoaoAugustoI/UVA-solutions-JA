#include <bits/stdc++.h>

using namespace std;
vector<int> adjlist[210];
int cor[210],pretos = 0,brancos = 0,guardas;
int V,E;
bool bip;
void coloregrafo(int v)
{
    cor[v] = 0;
    brancos++;
    queue <int> kiwi;
    kiwi.push(v);

    while(kiwi.size())
    {
        int x = kiwi.front();
        kiwi.pop();
        for(int i=0;i<(int(adjlist[x].size()));i++)
        {
            int u = adjlist[x][i];
            if(cor[u] == -1)
            {
                cor[u] = 1 - cor[x];
                kiwi.push(u);
                if(cor[u] == 0)
                    brancos++;
                if(cor[u] == 1)
                    pretos++;
            }
            if(cor[u] == cor[x])
            {
                bip = false;
                return;
            }
        }
    }
}

bool bipartido()
{
    guardas = 0;
    for(int i=0;i<V;i++)
    {
        pretos = 0;brancos = 0;
        if(cor[i] == -1)
        {
            coloregrafo(i);
            int aux = min(pretos,brancos);
            //cout<<"pretos: "<<pretos<<endl;
            //cout<<"brancos: "<<brancos<<endl;
            if(!aux)
                guardas++;
            else
                guardas+=aux;
            //cout<<"guardas: "<<guardas<<endl;
        }
    }
    if(!bip)
        return false;
    return true;
}

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        bip = true;

        cin>>V>>E;
        for(int i=0;i<E;i++)
        {
            int f,t;
            cin>>f>>t;
            adjlist[f].push_back(t);
            adjlist[t].push_back(f);
        }
        for(int i=0;i<V;i++)
            cor[i] = -1;
        if(bipartido())
        {
            cout<<guardas<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        for(int i=0;i<V;i++)
        {
            adjlist[i].clear();
        }
    }
}
