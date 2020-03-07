#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    ull fat[23]{1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
    int t;
    string s;

    cin>>t;

    for(int i = 1;i<=t;i++)
    {
        map<char,ull>letras;
        cin>>s;

        for(int j = 0;j<(int)s.size();j++)
        {
            letras[s[j]]++;
        }
        ull x = fat[s.size()];
        for(int j = 65;j<92;j++)
        {
            if(letras[(char)j])
                x = x/fat[letras[(char)j]];
        }

        printf("Data set %d: ",i);
        cout<<x<<endl;
    }
}
