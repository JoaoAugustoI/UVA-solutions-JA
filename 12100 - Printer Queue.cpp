#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        priority_queue <int> verif;
        queue <pair<int,int> > x;
        for(int i=0;i<N;i++)
        {
            int aux;
            cin>>aux;
            x.push(make_pair(aux,i));
            verif.push(aux);
        }
        int time = 0;
        while(true)
        {
            pair<int,int> aux;
            aux = x.front();
            x.pop();
            if(aux.first == verif.top())
            {
                verif.pop();
                time++;
                if(aux.second == M)
                    break;
            }
            else
            {
                x.push(aux);
            }
        }
        cout<<time<<endl;
    }
}
