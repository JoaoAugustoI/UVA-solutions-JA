#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int R,L,U;
int botoes[13];
int bfs(int inicio,int fim)
{
    int dist[11000];
    for(int i=0;i<11000;i++)
        dist[i] = INF;

    dist[inicio] = 0;
    queue<int> kiwi;
    kiwi.push(inicio);
    while(kiwi.size())
    {
        if(dist[fim] != INF)
            return dist[fim];
        int u = kiwi.front();kiwi.pop();
        for(int i=0;i<R;i++)
        {
            int v = u+botoes[i];
            v = v%10000;
            if(dist[v] == INF)
            {
                dist[v] = dist[u]+1;
                kiwi.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    int ct = 1;
    cin>>L>>U>>R;

    while(L or U or R)
    {
        for(int i=0;i<R;i++)
        {
            cin>>botoes[i];
        }
        int resp = bfs(L,U);
        printf("Case %d: ",ct++);
        if(resp>=0)
        {
            cout<<resp<<endl;
        }
        else
        {
            cout<<"Permanently Locked"<<endl;
        }
        cin>>L>>U>>R;
    }
}
