#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    bool flag = false;
    while(N--)
    {
        int B,SG,SB;
        multiset <int> Green,Blue;

        cin>>B>>SG>>SB;

        for(int i=0;i<SG;i++)
        {
            int aux;
            cin>>aux;
            Green.insert(aux);
        }

        for(int i=0;i<SB;i++)
        {
            int aux;
            cin>>aux;
            Blue.insert(aux);
        }

        while(!Green.empty() and !Blue.empty())
        {
            vector<int> vencedoresG,vencedoresB;
            for(int i=0;i<B;i++)
            {
                if(!Green.empty() and !Blue.empty())
                {
                    multiset<int>::iterator itG = --Green.end(),itB = --Blue.end();
                    if(*itG > *itB)
                    {
                        vencedoresG.push_back(*itG-*itB);
                        Green.erase(itG);
                        Blue.erase(itB);
                    }
                    else
                    {
                        if(*itG < *itB)
                        {
                            vencedoresB.push_back(*itB-*itG);
                            Green.erase(itG);
                            Blue.erase(itB);
                        }
                        else
                        {
                            Green.erase(itG);
                            Blue.erase(itB);
                        }
                    }
                }
            }
            for(unsigned int i=0;i<vencedoresG.size();i++)
            {
                Green.insert(vencedoresG[i]);
            }
            for(unsigned int i=0;i<vencedoresB.size();i++)
            {
                Blue.insert(vencedoresB[i]);
            }
        }

        if(flag)
            cout<<endl;
        flag = true;
        if(!Green.empty())
        {
            cout<<"green wins"<<endl;
            multiset<int>::iterator itG = --Green.end();
            for(;itG!=Green.begin();itG--)
            {
                cout<<*itG<<endl;
            }
            cout<<*itG<<endl;
        }
        else
        {
            if(!Blue.empty())
            {
                cout<<"blue wins"<<endl;
                multiset<int>::iterator itB = --Blue.end();
                for(;itB!=Blue.begin();itB--)
                {
                    cout<<*itB<<endl;
                }
                cout<<*itB<<endl;
            }
            else
            {
                cout<<"green and blue died"<<endl;
            }
        }
    }
}
