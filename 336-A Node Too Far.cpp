#include <bits/stdc++.h>
using namespace std;

map <long long int,vector<long long int> > adjlist;
map <long long int,long long int> dist;
int ttl,reachable;
void bfs(int inicio)
{
    queue <int> kiwi;
    kiwi.push(inicio);
    dist[inicio] = 0;
    while(!kiwi.empty())
    {
        int u = kiwi.front();
        kiwi.pop();
        for(unsigned int i=0;i<adjlist[u].size();i++)
        {
            int k = adjlist[u][i];
            if(dist.find(k)==dist.end())
            {
                dist[k] = dist[u]+1;
                if(dist[k]<=ttl)
                {
                    reachable++;
                    kiwi.push(k);
                }
            }
        }
    }
}

int main()
{
    int N;
    cin>>N;
    int cont = 1;
    while(N)
    {
        set <long long int> aux;
        int nodes = 0;
        for(int i=0;i<N;i++)
        {
            int aux1,aux2;
            cin>>aux1>>aux2;
            aux.insert(aux1);
            aux.insert(aux2);
            adjlist[aux1].push_back(aux2);
            adjlist[aux2].push_back(aux1);
        }

        nodes = aux.size();
        int aux1;
        cin>>aux1>>ttl;
        while(aux1 or ttl)
        {
            reachable = 1;
            bfs(aux1);
            int notreachable = adjlist.size()-reachable;
            cout<<"Case "<<cont++<<": "<<notreachable<<" nodes not reachable from node "<<aux1<<" with TTL = "<<ttl<<"."<<endl;
            dist.clear();
            cin>>aux1>>ttl;
        }
        adjlist.clear();
        cin>>N;
    }
}
