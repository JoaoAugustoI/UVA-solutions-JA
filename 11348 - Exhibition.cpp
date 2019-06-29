#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K,friends;
    cin>>K;
    for(int i=1;i<=K;i++)
    {
        map<int,unsigned int> p;
        map<int,set<int> > selos;
        int qtd;
        cin>>friends;
        for(int j=1;j<=friends;j++)
        {
            p[j] = 0;
            cin>>qtd;
            for(int k=0;k<qtd;k++)
            {
                int aux;
                cin>>aux;
                selos[aux].insert(j);
                //sort(selos[aux].begin(),selos[aux].end());
            }
        }


        set<int>::iterator itx;
        long double totaluniq = 0;
        for(map<int,set<int> >::iterator it = selos.begin();it!=selos.end();it++)
        {
           // aux = it->second.size();
           // it->second.erase(unique(it->second.begin(),it->second.end()),it->second.end());

            if(it->second.size() == 1)
            {
                itx = it->second.begin();
                p[*itx]++;
                totaluniq++;
            }
            else
            {

            }
        }

        long double prct;
        cout.precision(6);
        cout<<fixed;
        map<int,unsigned int>::iterator it2 = p.begin();
        prct = (it2->second*100)/totaluniq;
        cout<<"Case "<<i<<": ";
        cout<<prct<<"%";
        it2++;
        for(;it2!=p.end();it2++)
        {
             prct = (it2->second*100)/totaluniq;
            cout<<" "<<prct<<"%";
        }
        cout<<endl;
    }
}
