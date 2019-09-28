#include <bits/stdc++.h>

using namespace std;


int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N;
    cin>>N;
    while(N)
    {
        int matY[27][27];
        int matM[27][27];
        for(int i=0;i<27;i++)
        {
            for(int j=0;j<27;j++)
            {
                if(i == j)
                    matY[i][j] = matM[i][j] = 0;
                else
                    matY[i][j] = matM[i][j] = 1e9;
            }
        }
        for(int i=0;i<N;i++)
        {

            char a,b,c,d;
            int e;
            cin>>a>>b>>c>>d>>e;
            if(a == 'Y')
            {
                if(b == 'B')
                {
                    matY[c-65][d-65] = matY[d-65][c-65] = e;
                }
                else
                {
                    matY[c-65][d-65] = e;
                }
            }
            else
            {
                if(b == 'B')
                {
                    matM[c-65][d-65] = matM[d-65][c-65] = e;
                }
                else
                {
                    matM[c-65][d-65] = e;
                }
            }
        }
        char aux1,aux2;
        cin>>aux1>>aux2;
        int iniY = aux1-65,iniM = aux2-65;

        for (int k=0;k<26;k++)
        {
            for (int i=0;i<26;i++)
            {
                for (int j=0;j<26;j++)
                {
                    if (matY[i][k] + matY[k][j] < matY[i][j])
                    {
                        matY[i][j] = matY[i][k]+matY[k][j];
                    }
                    if (matM[i][k] + matM[k][j] < matM[i][j])
                    {
                        matM[i][j] = matM[i][k]+matM[k][j];
                    }
                }
            }
        }

        int aux = 1e9;
        for(int i=0;i<26;i++)
        {
            aux = min(aux,matY[iniY][i] + matM[iniM][i]);
        }


        if(aux == 1e9)
            cout<<"You will never meet."<<endl;
        else
        {
            if(iniY != iniM)
                cout<<aux<<" ";
            else
            {
                cout<<0<<" ";
            }
            vector<int> resp;
            for(int i=0;i<26;i++)
            {
                if(matY[iniY][i] + matM[iniM][i] == aux)
                {
                    resp.push_back(i+65);
                }
            }
            sort(resp.begin(),resp.end());
            cout<<char(resp[0]);
            for(int i=1;i<resp.size();i++)
            {
                cout<<" "<<char(resp[i]);
            }
            cout<<endl;
        }

        cin>>N;
    }

}
