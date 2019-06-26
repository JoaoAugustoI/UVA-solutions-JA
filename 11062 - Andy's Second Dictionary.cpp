#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> x;
    string palavras;
    char p;
    while(true)
    {
        p = char(getchar());
        if(p == EOF)
        {
            break;
        }

        if((p>=65 and p<=90))
        {
            p += 32;
            palavras.push_back(p);
        }
        else
        {
            if(p>=97 and p<=122)
            {
                palavras.push_back(p);
            }
            else
            {
                if(p == '-')
                {
                    palavras.push_back(p);
                }
                else
                {
                    if(p == '\n')
                    {
                        if(palavras[palavras.size()-1] == '-')
                        {
                            palavras.erase(palavras.size()-1);
                        }
                        else
                        {
                            if(!palavras.empty())
                            {
                                x.insert(palavras);
                                palavras.clear();
                            }

                        }
                    }
                    else
                    {
                        if(!palavras.empty())
                        {
                            x.insert(palavras);
                            palavras.clear();
                        }
                    }
                }
            }
        }
    }
    for(set<string>::iterator it = x.begin();it!=x.end();it++)
    {
        cout<<*it<<endl;
    }
}



