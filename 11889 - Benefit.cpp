#include <bits/stdc++.h>
#define ll long long int
#define intmax 10000100
using namespace std;

int mp[intmax]{};
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
}

int main()
{
    crivo();
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll A,C,B;
        cin>>A>>C;

        if(C%A != 0)
        {
            puts("NO SOLUTION");
        }
        else
        {
            map<int,int> mapaA,mapaC;
            while(A>1)
            {
                mapaA[mp[A]]++;
                mapaC[mp[A]] = 0;
                A = A/mp[A];
            }

            while(C>1)
            {
                mapaC[mp[C]]++;

                if(mapaA[mp[C]] == 0)
                {
                    mapaA[mp[C]] = 0;
                }
                C = C/mp[C];
            }
            B = 1;
            for(map<int,int>::iterator it = mapaA.begin(),it2 = mapaC.begin();it2!=mapaC.end();it++,it2++)
            {
                //cout<<it2->first<<" "<<it->first<<endl;
                if(it2->second > it->second)
                {
                    B *= pow(it2->first,it2->second);
                }
            }
            cout<<B<<endl;
        }

    }
}
