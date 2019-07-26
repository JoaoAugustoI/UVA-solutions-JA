#include <bits/stdc++.h>

using namespace std;
typedef vector <unsigned int> vt;
typedef pair <int,int> ii;

map<string,int> cidades;
vt P(10000,0);
vt qtd(10000,1);

vector<pair<int,ii> > Edjlist;

int Find(int u)
{
    if(u == P[u])
    {
        return u;
    }
    return Find(P[u]);
}

void UnionSet(int a, int b)
{
    a = Find(a);
    b = Find(b);
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
}

int main()
{
    int t;
    bool flag = 0;
    while(cin>>t)
    {
        while(t--)
        {
            int ct = 1;
            if(flag)
                cout<<"\n";
            flag = true;
            int sum = 0,m,n;
            cin>>n>>m;

            for(int i=1;i<=n;i++)
            {
                P[i] = i;
                qtd[i] = 1;
            }
            string x,y;
            for(int i=0;i<m;i++)
            {
                int z;
                cin>>x>>y>>z;
                if(!cidades.count(x))
                    cidades[x] = ct++;
                if(!cidades.count(y))
                    cidades[y] = ct++;
                Edjlist.push_back(make_pair(z,ii(cidades[x],cidades[y])));
                Edjlist.push_back(make_pair(z,ii(cidades[y],cidades[x])));
            }
            sort(Edjlist.begin(),Edjlist.end());
            for(int i=0;i<Edjlist.size();i++)
            {
                if(Find(Edjlist[i].second.first) != Find(Edjlist[i].second.second))
                {
                    UnionSet(Edjlist[i].second.first,Edjlist[i].second.second);
                    sum+=Edjlist[i].first;
                }
            }
            Edjlist.clear();
            cidades.clear();
            cout<<sum<<endl;
        }
    }
}


