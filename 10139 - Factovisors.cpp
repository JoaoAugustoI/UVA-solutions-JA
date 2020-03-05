#include <bits/stdc++.h>

using namespace std;

int get_powers(int n, int p)
{
    int result = 0;
    n /= p;
    do
    {
        result += n;
        n /= p;
    }while(n > 0);

    return result;
}

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N,M;

    while(cin>>N>>M)
    {
        if(M == 0)
        {
            printf("%d divides %d!\n",M,N);
        }
        else
        {
            if(N == 0 or N == 1)
            {
                if(M>1)
                    printf("%d does not divide %d!\n",M,N);
                else
                    printf("%d divides %d!\n",M,N);
            }
            else
            {
                bool flag = true;
                vector<int> fac;
                int aux = M;
                for(int i = 2;i*i<=aux;i++)
                {
                    int cont = 0;
                    if(aux%i == 0)
                    {
                        fac.push_back(i);
                        while(aux%i == 0)
                        {
                            aux/=i;
                            cont++;
                        }
                        fac.push_back(cont);
                    }
                }
                if (aux > 1)
                {
                    if (N < aux)
                    {
                        flag = false;
                    }
                    else
                    {
                        fac.push_back(aux);
                        fac.push_back(1);
                    }
                }
                for(int i = 1;i<(int)fac.size();i+=2)
                {
                    if(fac[i] - get_powers(N,fac[i-1]) > 0)
                    {
                        flag = false;
                        i = fac.size();
                    }
                }

                if(flag)
                {
                    printf("%d divides %d!\n",M,N);
                }
                else
                {
                    printf("%d does not divide %d!\n",M,N);
                }
            }
        }
    }
}
