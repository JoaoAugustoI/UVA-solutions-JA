#include <bits/stdc++.h>

using namespace std;
char mat[110][110];
char vet[60010];
int N,M,S;
int startX,startY;
char inipos;

int pos(char x)
{
    if(x == 'N')
        return 0;
    if(x == 'S')
        return 2;
    if(x == 'O')
        return 3;
    if(x == 'L')
        return 1;
    return 0;
}

bool verif_pos(int x,int y)
{
    if(x>=0 and x<N and y<M and y>=0 and mat[x][y]!='#')
        return true;
    return false;
}

int bfs()
{
    int contador = 0;
    int x = startX;
    int y = startY;
    int d = pos(inipos);
    vet[S] = 'x';
    for(int i=0;i<=S;i++)
    {
		//printf("posicao (%d,%d) direcao: %d , comando: %c, matriz: %c\n",x,y,d,vet[i],mat[x][y]);
        if(mat[x][y] == '*')
        {
            mat[x][y] = '.';
            contador++;
        }
        if(vet[i] == 'D')
        {
            d = (d+1)%4;
        }
        else
        {
            if(vet[i] == 'E')
            {
                if(d == 0)
                    d = 4;
                d--;
            }
            else
            {
                if(vet[i] == 'F')
                {
                    if(d == 0)
                    {
                        if(verif_pos(x-1,y))
                        {
                            x--;
                        }
                    }
                    if(d == 1)
                    {
                        if(verif_pos(x,y+1))
                        {
                            y++;
                        }
                    }
                    if(d == 2)
                    {
                        if(verif_pos(x+1,y))
                        {
                            x++;
                        }
                    }
                    if(d == 3)
                    {
                        if(verif_pos(x,y-1))
                        {

                            y--;
                        }
                    }
                }
            }
        }
    }
    return contador;
}



int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>N>>M>>S;
    while(N or M or S)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]>=65 and mat[i][j]<=90)
                {
                    startX = i;startY = j;
                    inipos = mat[i][j];
                }
            }
        }
        for(int i=0;i<S;i++)
        {
            cin>>vet[i];
        }
        cout<<bfs()<<endl;

        cin>>N>>M>>S;
    }
}
