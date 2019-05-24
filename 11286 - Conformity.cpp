#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N)
    {
        int qtd = 0;
        int maior = 0;
        map<vector<int>,int> cursos;
        int x;
        for(int j=0;j<N;j++)
        {
            vector<int> aux;
            for(int i=0;i<5;i++)
            {
                cin>>x;
                aux.push_back(x);
            }
            sort(aux.begin(),aux.end());
            cursos[aux]++;
            if(cursos[aux]>maior)
            {
                maior = cursos[aux];
                qtd = 0;
            }

            if(cursos[aux] == maior)
                qtd += maior;

        }
        cout<<qtd<<endl;
        cin>>N;
    }
}
