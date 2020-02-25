#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while( cin>>N)
    {

        int vet[6000];
        vet[0] = 1;
        int k = 1;
        int quoc = 0;
        for(int i = 2;i<=N;i++)
        {
            for(int j = 0;j<k;j++)
            {
                int aux = vet[j]*i+quoc;
                vet[j] = aux%10;
                quoc = aux/10;
            }

            while(quoc)
            {
                vet[k] = quoc%10;
                quoc /= 10;
                k++;
            }

        }
        printf("%d!\n",N);
        for(int i = k-1;i>=0;i--)
        {
            cout<<vet[i];
        }
        puts("");
    }
}
