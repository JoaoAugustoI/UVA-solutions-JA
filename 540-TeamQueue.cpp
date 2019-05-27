#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,N;
    int f = 1;
    cin>>t;
    while(t)
    {
        map<int, queue<int> >mapadetimes;
        map<int,int> times;
        queue <int> Numtimes;
        int aux;
        for(int j=1;j<=t;j++)
        {
            cin>>N;
            for(int i=0;i<N;i++)
            {
                cin>>aux;
                times[aux] = j;
                cout<<"times["<<aux<<"] vale: "<<times[aux]<<endl;
            }
        }

        string comando;
        cout<<"Scenario #"<<f<<endl;
        f++;
        cin>>comando;
        while(comando!="STOP")
        {
            if(comando == "ENQUEUE")
            {
                int aux1;
                cin>>aux1;
                 cout<<"times["<<aux1<<"] vale: "<<times[aux1]<<endl;
                if(mapadetimes[times[aux1]].empty())
                {
                    Numtimes.push(times[aux1]);
                    cout<<"ADICIONOU: "<<times[aux1]<<" NA FILA"<<endl;
                    mapadetimes[times[aux1]].push(aux1);
                }
                else
                {
                    mapadetimes[times[aux1]].push(aux1);
                }
            }
            else
            {
                if(comando == "DEQUEUE")
                {
                    cout<<"FRENTE DA FILA: "<<Numtimes.front()<<endl;
                    if(mapadetimes[Numtimes.front()].empty())
                    {
                        Numtimes.pop();
                    }
                    cout<<mapadetimes[Numtimes.front()].front()<<endl;
                    mapadetimes[Numtimes.front()].pop();
                }
            }
            cin>>comando;
        }
        cout<<endl;
        cin>>t;
    }
}

