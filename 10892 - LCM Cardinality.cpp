#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    ll N;
    cin>>N;
    while(N)
    {
        vector<ll> fac;
        for(ll i = 1;i*i<=N;i++)
        {
            if(N%i == 0)
            {
                if(i*i==N)
                {
                    fac.push_back(i);
                }
                else
                {
                    fac.push_back(N/i);fac.push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0;i<fac.size();i++)
        {
            for(int j = i;j<fac.size();j++)
            {
                if((fac[i]/gcd(fac[i],fac[j]))*fac[j] == N)
                {
                    count++;
                }
            }
        }

        cout<<N<<" "<<count<<endl;
        cin>>N;
    }
}
