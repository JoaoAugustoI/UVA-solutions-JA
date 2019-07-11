
	
#include <bits/stdc++.h>
using namespace std;

int main()
{
   
    int N,C;

    cin>>N;
    while(N--)
    {
        bool flag = false;
        cin>>C;
        vector<pair<string,bool> > impr;
        map<string,pair<set<string>,pair<int,int> > > x;
        for(int i=0;i<C;i++)
        {
            int aux,aux2;
            string categorie;
            cin>>categorie>>aux>>aux2;
            if(!aux2)
            {
                flag = true;
                impr.push_back(make_pair(categorie,true));
            }
            else
                impr.push_back(make_pair(categorie,false));

            x[categorie].second.second = aux2;
            for(int j=0;j<aux;j++)
            {
                string k;
                cin>>k;
                x[categorie].first.insert(k);

            }
            x[categorie].second.first = x[categorie].first.size();
        }

        unsigned int aux;

        string linha;
         cin.ignore(1200,'\n');
        while(getline(cin,linha))
        {
            aux = linha.size();
            if(!aux)
                break;
            string palavra = "";
            for(unsigned int i=0;i<aux;i++)
            {
                if((linha[i]>='A' and linha[i]<='Z') or (linha[i]>='a' and linha[i]<='z'))
                    palavra+=linha[i];
                else
                {
                    if(palavra.size())
                    {
                        for(map<string,pair<set<string>,pair<int,int> > >::iterator it = x.begin();it!=x.end();it++)
                        {
                            if(it->second.first.find(palavra)!=it->second.first.end())
                            {
                                it->second.first.erase(palavra);
                            }
                            if((it->second.second.first-it->second.first.size()) >= it->second.second.second)
                            {
                                for(unsigned int i=0;i<impr.size();i++)
                                {
                                    if(it->first == impr[i].first)
                                    {
                                        flag = true;
                                        impr[i].second = true;
                                    }
                                }
                            }
                        }
                    }
                    palavra = "";
                }
            }
            if(palavra.size())
            {
                for(map<string,pair<set<string>,pair<int,int> > >::iterator it = x.begin();it!=x.end();it++)
                {
                    if(it->second.first.find(palavra)!=it->second.first.end())
                    {
                        it->second.first.erase(palavra);
                    }
                    if((it->second.second.first-it->second.first.size()) == it->second.second.second)
                    {
                        for(unsigned int i=0;i<impr.size();i++)
                        {
                            if(it->first == impr[i].first)
                            {
                                flag = true;
                                impr[i].second = true;

                            }
                        }
                    }
                }
            }
        }

        if(!flag)
        {
            cout<<"SQF Problem."<<endl;
        }
        else
        {
            vector<string> out;
            for(int i=0;i<impr.size();i++)
            {
                if(impr[i].second)
                    out.push_back(impr[i].first);
            }
            cout<<out[0];
            for(int i=1;i<out.size();i++)
            {
                cout<<","<<out[i];
            }
            cout<<endl;
        }
    }
}

