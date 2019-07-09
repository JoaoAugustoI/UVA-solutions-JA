#include <bits/stdc++.h>
using namespace std;

int main()
{
    string T;
    int cont = 1;
    cin>>T;
    while(T != "end")
    {
        map<int,stack<char> > containers;
        for(unsigned int i=0;i<T.size();i++)
        {
            unsigned int pos = 0;
            if(containers.empty())
            {
                containers[0].push(T[i]);
            }
            else
            {
                while(!containers[pos].empty() and T[i] > containers[pos].top())
                {
                    pos++;
                }
                containers[pos].push(T[i]);
            }
        }
        cout<<"Case "<<cont++<<": "<<containers.size()<<endl;
        cin>>T;
    }
}
