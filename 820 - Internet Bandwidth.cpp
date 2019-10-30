#include <bits/stdc++.h>

using namespace std;
int s,t,c,n,f,mf;
int mat[104][104];
int p[104];
void fluxo(int v,int MinF)
{
    if(v == s)
    {
        f = MinF;
        return;
    }
    else
    {
        if(p[v]!=-1)
        {
            fluxo(p[v],min(MinF,mat[p[v]][v]));
            mat[p[v]][v] -= f;
            //mat[v][p[v]] += f;
        }
    }
}

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>n;
    int cont = 1;
    while(n)
    {
        cin>>s>>t>>c;


        for(int i=0;i<104;i++)
        {
            for(int j=0;j<104;j++)
            {
                mat[i][j] = 0;
            }
        }
        for(int i=0;i<c;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            mat[x][y] += z;
            mat[y][x] += z;
        }
        mf = 0;
        while(true)
        {
            f = 0;
            bool visitados[104];
            for(int i=0;i<104;i++)
            {
                visitados[i] = 0;
                p[i] = -1;
            }

            queue<int> kiwi;

            kiwi.push(s);
            visitados[s] = true;

            while(kiwi.size())
            {
                int u = kiwi.front();
                kiwi.pop();
                if(u == t)
                    break;
                for(int i = 1;i<=n;i++)
                {
                    if(mat[u][i]>0 and !visitados[i])
                    {
                        kiwi.push(i);
                        visitados[i] = true;
                        p[i] = u;
                    }
                }
            }
            fluxo(t,1e9);
            if(f == 0)
                break;
            mf+=f;
        }
        cout<<"Network "<<cont++<<endl;
        printf("The bandwidth is %d.\n\n",mf);
        cin>>n;
    }

}
