#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N,aux;

    cin>>T;

    while(T--)
    {
        stack <int> P1,P2;
        set <int> verif;
        int cont = 0,max = 0;
        cin>>N;
        while(N--)
        {
            cin>>aux;
            P1.push(aux);
            if(verif.find(aux) == verif.end())
            {
                verif.insert(aux);
                cont++;
            }
            else
            {
                if(cont>max)
                {
                    max = cont;
                }
                P2.push(P1.top());
                P1.pop();
                while(P1.top()!=aux)
                {
                    P2.push(P1.top());
                    P1.pop();
                }
                cont = 0;
                verif.clear();
                while(P2.size())
                {
                    P1.push(P2.top());
                    verif.insert(P2.top());
                    P2.pop();
                    cont++;
                }
            }
        }
        if(cont>max)
        {
            max = cont;
        }
        cout<<max<<endl;
    }
}
