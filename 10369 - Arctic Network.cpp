#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vt;
typedef pair <int,int> ii;

vt P;
vt qtd;
vector<pair<double,double> > outpost;
vector<pair<double,ii> > Edgelist;

int Find(int u)
{
    if(u == P[u])
    {
        return u;
    }
    return Find(P[u]);
}

bool UnionSet(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a!=b)//nao tem o mesmo pai
    {
        if(qtd[a] > qtd[b])
        {
            P[b] = a;
            qtd[a] += qtd[b];
        }
        else
        {
            P[a] = b;
            qtd[b] += qtd[a];
        }
        return true;
    }
    return false;
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int N;
    cin>>N;
    while(N--)
    {
        int S,p;
        cin>>S>>p;
        for(int i=0;i<p;i++)
        {
            P.push_back(i);
            qtd.push_back(1);
        }

        for(int i=0;i<p;i++)
        {
            double x,y;
            cin>>x>>y;
            outpost.push_back(make_pair(x,y));
        }

        for(int i=0;i<p;i++)
        {
            for(int j=i+1;j<p;j++)
            {
                double dist = sqrt(((outpost[i].first - outpost[j].first)*(outpost[i].first - outpost[j].first))+((outpost[i].second - outpost[j].second)*(outpost[i].second - outpost[j].second)));
                Edgelist.push_back(make_pair(dist,make_pair(i,j)));
                //cout<<"dist: "<<dist<<endl;
            }
        }
        int sum = 0;
        double maior = 0;
        sort(Edgelist.begin(),Edgelist.end());


        for(int i=0;i<int(Edgelist.size());i++)
        {
            if(Find(Edgelist[i].second.first) != Find(Edgelist[i].second.second))
            {
                if(p-S == sum)
                {
                    i = Edgelist.size();
                    break;
                }
                UnionSet(Edgelist[i].second.first,Edgelist[i].second.second);
                sum++;
                maior = max(maior,Edgelist[i].first);
            }
        }

        cout<<fixed;
        cout.precision(2);
        cout<<maior<<endl;
        outpost.clear();
        P.clear();
        qtd.clear();
        Edgelist.clear();
    }
}
