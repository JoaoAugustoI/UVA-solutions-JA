#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int T;

    cin>>T;
    for(int i = 1;i<=T;i++)
    {
        int cnt = 0;
        int N;
        cin>>N;
        char vet[N];
        for(int j = 0;j<N;j++)
        {
            cin>>vet[j];
        }

        int j = 0;
        while(j<N)
        {
            if(j>0)
            {
                if(j<N-1)
                {
                    if(vet[j-1]=='.' and vet[j+1]=='.')
                    {
                        vet[j] = vet[j-1] = vet[j+1] = '#';
                        cnt++;
                    }
                }

                if(vet[j-1]=='.')
                {
                    cnt++;
                    vet[j-1] = vet[j] = '#';
                }
            }
            j++;
        }
        if(vet[N-1] == '.')
            cnt++;

        printf("Case %d: %d\n",i,cnt);
    }

}
