
#include <bits/stdc++.h>
#define INF 99999
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<pair<int,int> > adjlist[1010];
        int N,M;
        int dist[1010];
        cin>>N>>M;
        for(int i=0;i<N;i++)
            dist[i] = INF;

        for(int i=0;i<M;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            adjlist[x].push_back(make_pair(y,z));
        }

        dist[0] = 0;
        for(int i=1;i<N;i++)
            for(int at=0;at<N;at++)
            {
                for(pair<int,int> to : adjlist[at])
                {
                    dist[to.first] = min(dist[at] + to.second, dist[to.first]);
                }
            }

        bool flag = false;
        for(int at=0;at<N;at++)
        {
            for(pair<int,int> to :adjlist[at])
            {
                if(dist[to.first] > to.second+dist[at])
                {
                    flag = true;
                    at = N;
                    break;
                }
            }
        }

        if(flag)
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;
    }
}
