#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int N;
    long long int limite = 10000000;

    bitset <10000001> b;
    vector<int> primos;
    b.set();
    b[0] = b[1] = false;

    for(long long int i = 2;i <= limite;i++)
    {
        if(b[i])
        {
            primos.push_back(i);
            for(long long int j = i*i;j<=limite;j+=i)
            {
                b[j] = false;
            }
        }
    }
    cin>>N;
    while(N)
    {
        long long int aux = N;
        vector<long long int> fatores;
        if(N<0)
        {
            fatores.push_back(-1);
            N = N*-1;
        }
        int i = 0;
        long long int fp = primos[i];
        while(fp*fp<=N)
        {
            //cout<<fp<<endl;
            while(N%fp == 0)
            {
                fatores.push_back(fp);
                N/=fp;
            }
            fp = primos[++i];
        }
        if(N!=1)
            fatores.push_back(N);
        cout<<aux<<" = "<<fatores[0];
        for(int i = 1;i<fatores.size();i++)
        {
            cout<<" x "<<fatores[i];
        }
        cout<<endl;
        cin>>N;
    }



}
