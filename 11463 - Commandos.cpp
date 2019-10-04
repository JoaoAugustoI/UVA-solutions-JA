#include <bits/stdc++.h>
#define INF 1e8

using namespace std;

int main()
{
    int T;

    cin>>T;

    for(int c=1;c<=T;c++)
    {
        int N;
        cin>>N;
        int mat[200][200];

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                mat[i][j] = mat[j][i] = INF;
                if(i==j)
                    mat[i][j] = 0;
            }
        }
        int R;
        cin>>R;
        for(int i=0;i<R;i++)
        {
            int x,y;
            cin>>x>>y;
            mat[x][y] = mat[y][x] = 1;
        }
        int s,d;
        cin>>s>>d;
        for(int k=0;k<N;k++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        
        int maiorini = 0;
        for(int i=0;i<N;i++)
        {
            if(mat[s][i]!=INF and mat[d][i])
                maiorini = max(maiorini,mat[s][i]+mat[d][i]);
        }

        printf("Case %d: %d\n",c,maiorini);
    }
}
