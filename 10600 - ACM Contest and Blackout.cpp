#include <bits/stdc++.h>

using namespace std;

int qtd[200100];
int P[200100];


int UnionFind(int u)
{
    if(P[u] == u)
        return u;
    return UnionFind(P[u]);
}

void UnionSet(int x,int y)
{
    x = UnionFind(x);
    y = UnionFind(y);

    if(qtd[x]>qtd[y])
    {
        P[y] = x;
        qtd[x] += qtd[y];
    }
    else
    {
        P[x] = y;
        qtd[y] += qtd[x];
    }
}


int main()
{	//freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N,M;
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,pair<int,int> > > EdgeList,MST;
        cin>>N>>M;

        for(int i=0;i<=N;i++)
        {
            P[i] = i;
            qtd[i] = 1;
        }
        for(int i=0;i<M;i++)
        {
            int x,y,z;

            cin>>x>>y>>z;
            EdgeList.push_back(make_pair(z,make_pair(x,y)));

        }
        sort(EdgeList.begin(),EdgeList.end());
        int sum = 0;
        for(int i=0;i<EdgeList.size();i++)
        {
            if(UnionFind(EdgeList[i].second.first) != UnionFind(EdgeList[i].second.second))
            {
                UnionSet(EdgeList[i].second.first,EdgeList[i].second.second);
                sum+=EdgeList[i].first;
                //printf("mst1 = aresta:(%d,%d) peso: %d\n",EdgeList[i].second.first,EdgeList[i].second.second,EdgeList[i].first);
                MST.push_back(make_pair(EdgeList[i].first,make_pair(EdgeList[i].second.first,EdgeList[i].second.second)));
            }
        }
        
        //cout<<"qtd de vertices na arvore: "<<MST.size()+1<<endl;
        //cout<<endl<<endl;
        int sum2 = 1e9;
        sort(EdgeList.begin(),EdgeList.end());
        sort(MST.begin(),MST.end());
        for(int i=0;i<MST.size();i++)
        {
            for(int k=0;k<=N;k++)
            {
                P[k] = k;
                qtd[k] = 1;
            }
            int aux = 0;
            int cont = 0;
            for(int j=0;j<EdgeList.size();j++)
            {
                if(MST[i].second.first != EdgeList[j].second.first or MST[i].second.second != EdgeList[j].second.second)
                {
                    //printf("passou pela aresta: (%d,%d) peso: %d\n",EdgeList[j].second.first,EdgeList[j].second.second,EdgeList[j].first);
                    if(UnionFind(EdgeList[j].second.first) != UnionFind(EdgeList[j].second.second))
                    {
                        //printf("mst2 = aresta:(%d,%d) peso: %d\n",EdgeList[j].second.first,EdgeList[j].second.second,EdgeList[j].first);
                        UnionSet(EdgeList[j].second.first,EdgeList[j].second.second);
                        aux+=EdgeList[j].first;
                        cont++;
                    }
                }
            }
            //cout<<endl<<endl;
            if(cont+1 == N)
                sum2 = min(sum2,aux);
        }

        cout<<sum<<" "<<sum2<<endl;
        EdgeList.clear();
    }

}
