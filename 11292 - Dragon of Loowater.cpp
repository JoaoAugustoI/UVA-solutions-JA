#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b)
{
    if(a>b)
        return true;
    return false;
}
int main()
{
    int N,M;

    cin>>N>>M;
    while(N and M)
    {
        int dragon[N],knights[M],chosen[M];
        for(int i = 0;i<N;i++)
        {
            cin>>dragon[i];
        }
        sort(dragon,dragon+N);
        int j = 0;
        for(int i = 0;i<M;i++)
        {
            cin>>knights[i];
            if(knights[i]>=dragon[0])
            {
                chosen[j++] = knights[i];
            }
        }

        sort(chosen,chosen+j);

        int valor = 0,k = 0;
        for(int i = 0;i<j;i++)
        {
            if(chosen[i]>=dragon[k])
            {
                valor+=chosen[i];
                k++;
            }
        }

        if(k<N)
        {
            cout<<"Loowater is doomed!"<<endl;
        }
        else
        {
            cout<<valor<<endl;
        }
        cin>>N>>M;
    }
}
