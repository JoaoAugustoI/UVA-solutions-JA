#include <bits/stdc++.h>

using namespace std;
int L;
vector<char>mat [35];
void backtracking(int i, int j)
{
    mat[i][j] = '#';
    if(i>0 and mat[i-1][j] == ' ')
        backtracking(i-1,j);
    if(i<L-1 and mat[i+1][j] == ' ')
        backtracking(i+1,j);
    if(j>0 and mat[i][j-1] == ' ')
        backtracking(i,j-1);
    if(j<mat[i].size()-1 and mat[i][j+1] == ' ')
        backtracking(i,j+1);
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N;
    cin>>N;
    cin.ignore();
    while(N--)
    {
        int ini,cio;
        int i = 0;
        while(true)
        {
            string aux;
            getline(cin,aux);
            for(int j=0;j<aux.size();j++)
            {
                mat[i].push_back(aux[j]);
                if(mat[i][j] == '*')
                {
                    ini = i;
                    cio = j;
                }
            }
            if(aux[0]=='_')
            {
                L = i+1;
                break;
            }
            i++;
        }
        int cont = 0;
        backtracking(ini,cio);
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                cout<<mat[i][j];
            }
            mat[i].clear();
            cout<<endl;
        }
    }
}
