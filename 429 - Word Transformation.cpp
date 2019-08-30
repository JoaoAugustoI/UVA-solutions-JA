#include <bits/stdc++.h>

using namespace std;


map <string,vector<string> > grafo;
vector<string> auxiliar;

int bfs(string inicio,string fim)
{
    map<string,int> dist;
    dist[inicio] = 0;
    queue <string> kiwi;
    kiwi.push(inicio);
    while(kiwi.size())
    {
        string u = kiwi.front();
        kiwi.pop();
        for(int i=0;i<grafo[u].size();i++)
        {
            string v = grafo[u][i];
            if(!dist.count(v))
            {
                dist[v] = dist[u]+1;
                kiwi.push(v);
            }
        }
    }
    return dist[fim];
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N;

    cin>>N;
    while(N--)
    {
        string x;
        cin>>x;
        while(x!="*")
        {

            for(int i=0;i<auxiliar.size();i++)
            {
                if(x.size() == auxiliar[i].size())
                {
                    int dif = 0;
                    for(int j=0;j<auxiliar[i].size() and dif<=1;j++)
                    {
                        if(x[j] != auxiliar[i][j])
                        {
                            dif++;
                        }
                    }
                    if(dif<=1)
                    {
                        grafo[auxiliar[i]].push_back(x);
                        grafo[x].push_back(auxiliar[i]);
                    }
                }
            }
            auxiliar.push_back(x);

            cin>>x;
        }
        cin.ignore();
        string linha,inicio,fim;
        getline(cin,linha);
        while(linha!="")
        {
            inicio = "";
            fim = "";
            int i=0;
            while(linha[i]!=' ')
            {
                inicio += linha[i];
                i++;
            }
            i++;
            while(i<linha.size())
            {
                fim+= linha[i];
                i++;
            }
            cout<<inicio<<" "<<fim<<" "<<bfs(inicio,fim)<<endl;
            getline(cin,linha);
        }
        if(N)
            cout<<endl;
        grafo.clear();
    }

}
