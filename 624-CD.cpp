#include <bits/stdc++.h>

using namespace std;
vector <int> musics,resp,vecaux;
int X,N,soma = 0;

void backtracking(int idx,int sum)
{
    if(sum>N)
        return;
    if(sum>soma)
    {
        soma = sum;
        resp = vecaux;
    }
    if(sum == N)
        return;

    if(idx == X)
        return;
    backtracking(idx+1,sum);
    vecaux.push_back(musics[idx]);
    backtracking(idx+1,sum+musics[idx]);
    vecaux.pop_back();
}

int main()
{
    int aux;
    while(cin>>N)
    {
        cin>>X;
        for(int i=0;i<X;i++)
        {
            cin>>aux;
            musics.push_back(aux);
        }
        soma = 0;
        backtracking(0,0);
        for(int i=0;i<resp.size();i++)
        {
            cout<<resp[i]<<" ";
        }
        cout<<"sum:"<<soma<<endl;
        resp.clear();
        musics.clear();
        vecaux.clear();
        soma = 0;
    }
}
