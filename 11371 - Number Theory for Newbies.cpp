#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    string X;

    while(cin>>X)
    {
        ll A = 0;
        ll mul = 1;
        sort(X.begin(),X.end(),cmp);

        for(int i = X.size()-1;i>=0;i--)
        {
            A = A + (ll)(X[i]-48)*mul;
            mul*=10;
        }
        sort(X.begin(),X.end());
        ll B = 0;
        mul = 1;
        if(X[0] == '0')
        {
            ll save = 0;
            for(int i = 0;i<X.size();i++)
            {
                if(X[i] != '0')
                {
                    save = i;
                    break;
                }
            }
            char aux = X[save];
            X[save] = X[0];
            X[0] = aux;
        }
        for(int i = X.size()-1;i>=0;i--)
        {
            B = B + (ll)(X[i]-48)*mul;
            mul*=10;
        }
        printf("%lld - %lld = %lld = 9 * %lld\n",A,B,A-B,(A-B)/9);
    }
}
