#include <bits/stdc++.h>

using namespace std;

set <vector<int> > visitados;

void imprimevector(vector<int> aux)
{
        cout<<"possibilidade: ";
        for(unsigned int i=0;i<aux.size();i++)
        {
            cout<<aux[i]<<" ";
        }
        cout<<"incluida";
        cout<<endl;
}

int bfs(vector<int>inicio,  vector<int>fim)
{

    map <vector<int>,int> dist;
    queue<vector<int> > kiwi;
    kiwi.push(inicio);
    dist[inicio] = 0;
    while(kiwi.size())
    {
        //ultimo numero--
        vector<int> u = kiwi.front();
        kiwi.pop();
        vector<int> aux1 = u;
        // cout<<dist[aux1]<<endl;
        aux1[3]--;
        if(aux1[3] == -1)
            aux1[3] = 9;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }

        aux1 = u;
        //penultimo numero--
        aux1[2]--;
        if(aux1[2] == -1)
            aux1[2] = 9;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }

        //segundo numero--
        aux1 = u;
        aux1[1]--;
        if(aux1[1] == -1)
            aux1[1] = 9;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }

        //primeiro numero--
        aux1 = u;
        aux1[0]--;
        if(aux1[0] == -1)
            aux1[0] = 9;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }

        aux1 = u;
            //primeiro numero++
        aux1[0] = (aux1[0]+1)%10;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }

        //segundo numero++
        aux1 = u;
        aux1[1] = (aux1[1]+1)%10;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }

        //terceiro numero++
        aux1 = u;
        aux1[2] = (aux1[2]+1)%10;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }

        //quarto numero++
        aux1 = u;
        aux1[3] = (aux1[3]+1)%10;
        if(visitados.find(aux1)==visitados.end() and dist.find(aux1)==dist.end())
        {
            //imprimevector(aux1);
            dist[aux1] = dist[u]+1;
            kiwi.push(aux1);
        }
    }

    if(dist.find(fim)!=dist.end())
        return dist[fim];
    return false;
}

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N;
    cin>>N;
    while(N--)
    {
        vector<int>start,target;
        for(int i=0;i<4;i++)
        {
            int p;
            cin>>p;
            start.push_back(p);
        }

        for(int i=0;i<4;i++)
        {
            int p;
            cin>>p;
            target.push_back(p);
        }

        int nc;
        cin>>nc;
        for(int i=0;i<nc;i++)
        {
            vector<int>aux;
            for(int i=0;i<4;i++)
            {
                int p;
                cin>>p;
                aux.push_back(p);
            }
            visitados.insert(aux);
        }
        if(target == start)
        {
            cout<<"0"<<endl;
        }
        else
        {
            int k = bfs(start,target);
        if(k)
            cout<<k<<endl;
        else
            cout<<-1<<endl;
        }
        visitados.clear();
    }
}
