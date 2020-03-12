#include <bits/stdc++.h>
#define LL long long int

using namespace std;


int main()
{
    LL N,M;
    while(cin>>N>>M)
    {
        LL resp = 1;
        LL aux = N-M+1;
        for(LL i=N;i>=aux;i--)
        {
            resp*=i;
            while(resp%10==0)
                resp/=10;
            
            resp=resp%1000000000;
            
        }
        cout<<resp%10<<endl;
        
    }
}
