#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        map<int,set<string>> final;
        map<string,int> ingredientes;
        string binder;
        cin.ignore();
        getline(cin,binder);
        for(unsigned int i=0;i<binder.size();i++)
        {
            if(binder[i]>=97 and binder[i]<=122)
            {
                binder[i] -= 32;
            }
        }
        int m,n,b;

        cin>>m>>n>>b;

        for(int i=0;i<m;i++)
        {
            string aux1;int aux2;
            cin>>aux1>>aux2;
            ingredientes[aux1] = aux2;
        }
        for(int i=0;i<n;i++)
        {
            cin.ignore();
            int price = 0;
            bool flag = false;
            string nome; int k;
            getline(cin,nome);
            cin>>k;
            for(int j=0;j<k;j++)
            {
                string aux1;int aux2;
                cin>>aux1>>aux2;
                price += ingredientes[aux1]*aux2;
                if(price>b)
                    flag = true;
            }
            if(!flag)
            {
                final[price].insert(nome);
            }
        }

        cout<<binder<<endl;
        if(final.size())
        {
            for(map<int,set<string>>::iterator it = final.begin();it!=final.end();it++)
            {
                for(set<string>::iterator it2 = final[it->first].begin();it2!=final[it->first].end();it2++)
                {
                    cout<<*it2<<endl;
                }
            }
        }
        else
        {
            cout<<"Too expensive!"<<endl;
        }
        cout<<endl;
    }
}


