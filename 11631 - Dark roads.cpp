#include <bits/stdc++.h>

using namespace std;
int N,M;
vector<int> qtd(2000100,1);
vector<int> P(200100,0);
vector<pair<int,pair<int,int> > > EdgeList;

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
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>N>>M;
    while(N or M)
    {
        int total = 0;

        for(int i=0;i<M;i++)
        {
            int x,y,z;

            cin>>x>>y>>z;
            total+=z;
            EdgeList.push_back(make_pair(z,make_pair(x,y)));
            P[x] = x;
            P[y] = y;
            qtd[x] =  qtd[y] = 1;
        }
        sort(EdgeList.begin(),EdgeList.end());
        int sum = 0;
        for(int i=0;i<EdgeList.size();i++)
        {
            if(UnionFind(EdgeList[i].second.first) != UnionFind(EdgeList[i].second.second))
            {
                UnionSet(EdgeList[i].second.first,EdgeList[i].second.second);
                sum+=EdgeList[i].first;
            }
        }
        EdgeList.clear();
        cout<<total-sum<<endl;
        cin>>N>>M;
    }

}
