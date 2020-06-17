#include <bits/stdc++.h>

using namespace std;
int N;
int cortes[1000];
int PD[60][1000];
int PUC(int i,int j)
{
    if(i+1 == j)
        return 0;
    if(PD[i][j] != -1)
    {
        return PD[i][j];
    }

    int resp = 1e9;
    for(int c = i+1;c<j;c++)
    {
        resp = min(resp,PUC(i,c)+PUC(c,j)+(cortes[j]-cortes[i]));
    }

    return PD[i][j] = resp;
}

int main()
{
    int tam;

    cin>>tam;
    while(tam)
    {
        cin>>N;
        memset(PD,-1,sizeof(PD));
        cortes[0] = 0;cortes[N+1] = tam;
        for(int i = 1;i<=N;i++)
        {
            cin>>cortes[i];
        }
        sort(cortes,cortes+N+1);
        printf("The minimum cutting is %d.\n",PUC(0,N+1));
        cin>>tam;
    }



    cin>>N;


}
