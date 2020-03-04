#include <bits/stdc++.h>
#define LL long long int
#define MAX 10000000
using namespace std;

vector<LL> primos;
bitset<MAX> bs;

/*void crivo()
{
    bs.set();
    bs[0] = bs[1] = 0;
    for(LL i = 2;i<=MAX;i++)
    {
        if(bs[i])
        {
            primos.push_back(i);
            for(LL j = i*i;j<=MAX;j+=i)
                bs[j] = 0;
        }
    }
}*/

int main()
{

    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    //crivo();
    LL N;
    cin>>N;
    while(N)
    {
        LL Ninicial = N;
        int cont = 0;
        LL maior = 0;
        for(LL i = 2;i*i<=abs(N) and abs(N)>1;i++)
        {
            if(N%i == 0)
            {
                maior = max(maior,i);
                cont++;
                while(N%i == 0)
                {
                    N/=i;
                }
            }
        }

        if(Ninicial!=N and abs(N)>1)
        {
            cout<<abs(N)<<endl;
        }
        else
        {
            if(cont>1)
            {
                cout<<maior<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }

        cin>>N;
    }
}
