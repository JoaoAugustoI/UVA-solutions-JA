#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N,cont = 1;

    while(cin>>N)
    {
        pair<int,pair<int,int> >adjlist[11000];
        int busyness[11000],dist[11000];
        for(int i=0;i<N;i++)
        {
            cin>>busyness[i];
        }

        int A;
        cin>>A;

        for(int i=0;i<A;i++)
        {
            int x,y,z;
            cin>>x>>y;
            z = busyness[y-1]-busyness[x-1];
            z = z*z*z;
            adjlist[i] = make_pair(z,make_pair(x,y));
        }

        for(int i=1;i<=N;i++)
            dist[i] = INF;
        dist[1] = 0;
        for(int i = 1;i<N;i++)
        {
            for(int j=0;j<A;j++)
            {
                int at = adjlist[j].second.first;
                int to = adjlist[j].second.second;
                int custoto = adjlist[j].first;
                //printf("(%d,%d) = ",at,to);
                //printf("%d = min(%d,%d+%d)\n",dist[to],dist[to],dist[at],custoto);
                if(dist[at]!=INF)
                {
                    dist[to] = min(dist[to],dist[at]+custoto);
                }
            }
        }

        bool ciclos[11000];
        for(int i=0;i<=N;i++)
            ciclos[i] = false;
        for(int j=0;j<A;j++)
        {
            int at = adjlist[j].second.first;
            int to = adjlist[j].second.second;
            int custoto = adjlist[j].first;
            //printf("(%d,%d) = ",at,to);
            //printf("%d > %d+%d\n",dist[to],custoto,dist[at]);
            if(dist[at] != INF and dist[to]>custoto+dist[at])
            {
                dist[to] = INF*(-1);//vértice to faz parte do ciclo, portanto, qualquer um
                ciclos[to] = true;  //adjacente a ele também faz, logo, seta ele com um valor
                //bastante baixo para ele desconsiderar os adjacentes na próxima
                //comparação
            }
        }

        for(int i=0;i<=N;i++)
        {
            if(ciclos[i] or dist[i] == INF)
                dist[i] = -1;
        }
        printf("Set #%d\n",cont++);

        int q;
        cin>>q;

        for(int i=0;i<q;i++)
        {
            int aux;
            cin>>aux;
            if(dist[aux]>=3)
            {
                cout<<dist[aux]<<endl;
            }
            else
            {
                cout<<"?"<<endl;
            }

        }
    }
}
