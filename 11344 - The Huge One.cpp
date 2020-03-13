#include <bits/stdc++.h>
#define ll long long int
#define intmax 10000100
using namespace std;

/*int mp[intmax]{};
vector<int> primos;
void crivo()
{

    for(int i = 2; i < intmax-1; i++)
        {
            if(!mp[i])
            {
                mp[i] = i;
                primos.push_back(i);
            }
            for(int j = 0; j < primos.size() && primos[j] <= mp[i] && i*primos[j] < intmax-1; j++)
            {
                mp[i*primos[j]] = primos[j];
            }
        }
}*/


bool divN(string X,int n)
{
    int sum = 0;
    for(int i = 0;i<X.size();i++)
    {
        sum = sum*10 + (int)(X[i]-48);
        sum = sum%n;
    }
    if(!sum)
        return true;
    return false;
}

bool divresp(int *vet,int tam,string X)
{
    for(int i = 0;i<tam;i++)
    {
        if(!divN(X,vet[i]))
            return false;
    }
    return true;
}


int main()
{
    int N;
    string M;

    cin>>N;

    while(N--)
    {
        cin>>M;

        int tam;
        cin>>tam;
        int vet[tam];
        for(int i = 0;i<tam;i++)
            cin>>vet[i];

        if(divresp(vet,tam,M))
        {
            cout<<M<<" - Wonderful."<<endl;
        }
        else
        {
            cout<<M<<" - Simple."<<endl;
        }
    }
}
