#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N;
    cin>>N;

    while(N)
    {
        string inicio,fim;

        map<string,vector<pair<pair<int,bool>,pair<string,string > > > > adjlist;
        cin>>inicio>>fim;
        for(int i=0;i<N;i++)
        {
            string x,y,aresta;
            cin>>x>>y>>aresta;
            adjlist[x].push_back(make_pair(make_pair(aresta.size(),false),make_pair(aresta,y)));
            adjlist[y].push_back(make_pair(make_pair(aresta.size(),false),make_pair(aresta,x)));
        }

        pair<pair<int,bool>,pair<string,string > > inipos;
        inipos.first.first = inipos.first.second = 0;
        inipos.second.first = "";
        inipos.second.second = inicio;
        priority_queue<pair<pair<int,bool>,pair<string,string> >,vector<pair<pair<int,bool>,pair<string,string> > >,greater<pair<pair<int,bool>,pair<string,string> > > >  kiwivip;
        kiwivip.push(inipos);
        int total = -1;
        while(kiwivip.size())
        {
            pair<pair<int,bool>,pair<string,string > > at;
            at = kiwivip.top();kiwivip.pop();
            if(at.second.second == fim)
            {
                total = at.first.first;
                break;
            }
            for(int i=0;i<adjlist[at.second.second].size();i++)
            {
                pair<pair<int,bool>,pair<string,string > > to = adjlist[at.second.second][i];
                if(!to.first.second and at.second.first[0]!=to.second.first[0])
                {
                    adjlist[at.second.second][i].first.second = true;
                    to.first.first += at.first.first;
                    kiwivip.push(to);
                }
            }
        }

        if(total!=-1)
        {
            cout<<total<<endl;
        }
        else
        {
            cout<<"impossivel"<<endl;
        }
        cin>>N;
    }
}
