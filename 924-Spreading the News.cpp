#include <bits/stdc++.h>

using namespace std;

map <int,vector<int> > friends;

int dias[2510];
int msmdia;
void bfs(int source)
{
    for(int i=0;i<2510;i++)
    {
        dias[i] = 100000;
    }
    queue<int> kiwi;
    kiwi.push(source);
    dias[source] = 0;
    while(kiwi.size())
    {
        source = kiwi.front();
        kiwi.pop();
        for(int i=0; i<friends[source].size(); i++)
        {
            int u = friends[source][i];
            if(dias[u]==100000)
            {
                dias[u] = dias[source]+1;
                kiwi.push(u);
                //cout<<"dias["<<u<<"]: "<<dias[u]<<endl;
            }
        }
    }
}


int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
    int N,aux1,aux2,T;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin>>aux1;
        for(int j=0;j<aux1;j++)
        {
            cin>>aux2;
            friends[i].push_back(aux2);
        }
    }
    cin>>T;
    int source,msmdia;
    int maxB,firstB;
    for(int i=0;i<T;i++)
    {
        maxB = firstB = 0;
        cin>>source;
        bfs(source);
        sort(dias,dias+N);
        msmdia = 1;
        int j;
        for(j=0;j<N-1;j++)
        {
            if(dias[j]==dias[j+1])
            {
                msmdia++;
            }
            else
            {

              //  cout<<"msmdia: "<<msmdia<<endl;
                if(msmdia>maxB and dias[j-1]!=100000)
                {
                    maxB = msmdia;
                    firstB = dias[j];
                }
                msmdia = 1;
            }
        }
        if(msmdia>maxB and dias[j-1]!=100000)
        {
            maxB = msmdia;
            firstB = dias[j-1];
        }
        if(!friends[source].size())
        {
            cout<<"0"<<endl;
        }
        else
        {
            if(!firstB)
                firstB++;
            cout<<maxB<<" "<<firstB<<endl;
        }
    }
}
