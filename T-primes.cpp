#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int limite = 1e7;
    bitset <10000000> bs;
    bs.set();
    set<long long int> Tprimos;
    for(long long int i = 2;i<=limite;i++)
    {
        if(bs[i] == true)
        {
            Tprimos.insert(i*i);
            for(long long int j = i*i;j<=limite;j+=i)
            {
                bs[j] = false;
            }
        }
    }

    int N;
    cin>>N;
    long long int vet[N];

    for(int i=0;i<N;i++)
    {
        cin>>vet[i];
    }

    for(int i=0;i<N;i++)
    {
        if(Tprimos.find(vet[i])!=Tprimos.end())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
