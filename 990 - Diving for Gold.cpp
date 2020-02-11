#include <bits/stdc++.h>

using namespace std;
int tam,w;
int OnePiece[32],Depth[32];
int laughtale[32][1300];
int PD[32][1300];
int diving(int i,int t)
{
    if(!t)
    {
        return 0;
    }
    if(i > tam)
    {
        return 0;
    }
    if(PD[i][t] != -1)
        return PD[i][t];

    int s = 3*w*Depth[i];
    int P1 = 0;
    if(s<=t)
    {
        P1 = OnePiece[i] + diving(i+1,t-s);
    }

    int P2 = diving(i+1,t);
    if(P1>P2)
    {
        laughtale[i][t] = true;
    }
    else
    {
        laughtale[i][t] = false;
    }

    return PD[i][t] = max(P1,P2);
}



int main()
{
    int t;
    bool f = false;
    while(cin>>t)
    {
        cin>>w;
        cin>>tam;
        for(int i = 0; i < 32;i++)
        {
            for(int j = 0;j<1300;j++)
            {
                PD[i][j] = -1;
                laughtale[i][j] = false;
            }
        }
        for(int i = 1 ;i<=tam;i++)
        {
            cin>>Depth[i]>>OnePiece[i];
        }
        if(f)
        {
            cout<<endl;
        }
        f = true;
        int soma,cont = 0,p = t;
        soma = diving(1,t);
        for(int i = 1;i<=tam;i++)
        {
            if(laughtale[i][p])
            {
                cont++;
                p -= 3*w*Depth[i];
            }
        }
        cout<<soma<<endl;
        cout<<cont<<endl;
        p = t;
        for(int i = 1;i<=tam;i++)
        {
            if(laughtale[i][p])
            {
                cout<<Depth[i]<<" "<<OnePiece[i]<<endl;
                p -= 3*w*Depth[i];
            }
        }
    }
}
