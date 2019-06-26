#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;

    cin>>T;

    while(T--)
    {
        map<string,string> antigo,update;
        string old, teen;
        string chave, valor;
        old = teen = "";
        cin>>old>>teen;
        for(unsigned int i=0;i<old.size();i++)
        {
            if(old[i]>=97 and old[i]<=122)
            {
                chave += old[i];
            }
            else
            {
                if(old[i]>=48 and old[i]<=57)
                {
                    valor += old[i];
                }
                else
                {
                    if(old[i] == ',' or old[i]== '}')
                    {
                        if(chave.size() and valor.size())
                        {
                            antigo[chave] = valor;
                            chave.clear();
                            valor.clear();
                        }
                    }
                }
            }
        }

        for(unsigned int i=0;i<teen.size();i++)
        {
            if(teen[i]>=97 and teen[i]<=122)
            {
                chave += teen[i];
            }
            else
            {
                if(teen[i]>=48 and teen[i]<=57)
                {
                    valor += teen[i];
                }
                else
                {
                    if(teen[i] == ',' or teen[i]== '}')
                    {
                        if(chave.size() and valor.size())
                        {
                            update[chave] = valor;
                            chave.clear();
                            valor.clear();
                        }
                    }
                }
            }
        }
        set <string> add,reduced,changed;
        set <string>::iterator it2;
        map<string,string>::iterator it;
        bool flag = false;
        for(it = update.begin();it != update.end();it++)
        {
            if(antigo.find(it->first) == antigo.end())
            {
                add.insert(it->first);
                flag = true;
            }
            else
            {
                if(antigo[it->first] != update[it->first])
                {
                    changed.insert(it->first);
                    flag = true;
                }
            }
        }

        for(it = antigo.begin();it != antigo.end();it++)
        {
            if(update.find(it->first) == update.end())
            {
                reduced.insert(it->first);
                flag = true;
            }
        }

        if(!flag)
            cout<<"No changes"<<endl;
        else
        {
            if(add.size())
            {
                cout<<"+";
                it2 = add.begin();
                cout<<*it2++;
                for(;it2!=add.end();it2++)
                {
                    cout<<","<<*it2;
                }
                cout<<endl;
            }
            if(reduced.size())
            {
                cout<<"-";
                it2 = reduced.begin();
                cout<<*it2++;
                for(;it2!=reduced.end();it2++)
                {
                    cout<<","<<*it2;
                }
                cout<<endl;
            }
            if(changed.size())
            {
                cout<<"*";
                it2 = changed.begin();
                cout<<*it2++;
                for(;it2!=changed.end();it2++)
                {
                    cout<<","<<*it2;
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }


}


