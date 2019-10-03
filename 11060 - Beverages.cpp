#include <bits/stdc++.h>

using namespace std;
vector<int> adjlist[1000];
int grau[1000],N;
map<string,int > mapa;
map<int,string> mapa2;
queue<int> resp;


void topological()
{
    priority_queue<int, vector<int>, greater<int> > kiwivip;
    for(int i=0;i<N;i++)
        if(!grau[i])
        {
            kiwivip.push(i);
        }

    while(kiwivip.size())
    {
        int at = kiwivip.top();
        kiwivip.pop();
        resp.push(at);
        for(int to : adjlist[at])
        {
            if(--grau[to] == 0)
            {
                kiwivip.push(to);
            }
        }
        adjlist[at].clear();
    }
}

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int c = 1;
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            string x;
            cin>>x;
            mapa[x] = i;
            mapa2[i] = x;
        }

        int M;
        cin>>M;
        for(int i=0;i<N;i++)
            grau[i] = 0;
        for(int i=0;i<M;i++)
        {
            string x,y;
            cin>>x>>y;
            grau[mapa[y]]++;
            adjlist[mapa[x]].push_back(mapa[y]);
        }
        topological();
        printf("Case #%d: Dilbert should drink beverages in this order: ",c++);
        cout<<mapa2[resp.front()];resp.pop();
        while(resp.size())
        {
            cout<<" "<<mapa2[resp.front()];
            resp.pop();
        }
        cout<<"."<<endl<<endl;
        mapa.clear();
        mapa2.clear();
        for(int i=0;i<N;i++)
            adjlist[i].clear();
    }

}
