#include <bits/stdc++.h>

using namespace std;

int N;
double prob;
double PD[60][30];
double tenis(int P,int V)
{
    if(V == N)
        return 1.0;
    if(P == 2*N-1)
        return 0.0;
    if(PD[P][V] != -1.0)
        return PD[P][V];

    double P1 = (1-prob) * tenis(P+1,V);
    double P2 = prob * tenis(P+1,V+1);

    return PD[P][V] = (P1 + P2);
}
int main()
{
    int T;

    scanf("%d",&T);
    while(T--)
    {
        for(int i = 0;i<60;i++)
            for(int j = 0;j<30;j++)
                PD[i][j] = -1.0;
        scanf("%d %lf",&N,&prob);
        printf("%.2lf\n",tenis(0,0));
    }
}
