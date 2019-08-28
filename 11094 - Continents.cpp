#include <bits/stdc++.h>

using namespace std;

char worldmap[21][21],conq;
int N,M,maior,cont;
int cordX,cordY;
void backtracking(int i,int j)
{
    cont++;
    worldmap[i][j] = conq+3;
    worldmap[i][j] = conq+3;
    if(i>0 and worldmap[i-1][j] == conq)
        backtracking(i-1,j);
    if(i < M-1 and worldmap[i+1][j] == conq)
        backtracking(i+1,j);
    if(j>0 and worldmap[i][j-1] == conq)
        backtracking(i,j-1);
    if(j< N-1 and worldmap[i][j+1] == conq)
        backtracking(i,j+1);
    if(j==0 and worldmap[i][N-1] == conq)
        backtracking(i,N-1);
    if(j==N-1 and worldmap[i][0] == conq)
        backtracking(i,0);
}

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    while(scanf("%d %d",&M,&N)!=EOF)
    {
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>worldmap[i][j];
            }
        }

        cin>>cordX>>cordY;
        conq = worldmap[cordX][cordY];

        backtracking(cordX,cordY);
        maior = 0;
        cont = 0;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(worldmap[i][j] == conq)
                {
                    cont = 0;
                    backtracking(i,j);
                    if(cont>maior)
                        maior = cont;
                }
            }
        }

        cout<<maior<<endl;
    }
}
