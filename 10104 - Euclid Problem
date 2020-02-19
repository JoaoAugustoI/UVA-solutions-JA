#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll x,y,d;

void euclids(ll a,ll b)
{
    if(b == 0)
    {
        x = 1; y = 0; d = a;
        return;
    }
    euclids(b,a%b);

    ll x1 = y;
    ll y1 = x - (a/b)*y;

    x = x1; y = y1;
}

int main()
{
    ll a,b;
    while(cin>>a>>b)
    {
        euclids(a,b);

        cout<<x<<" "<<y<<" "<<d<<endl;
    }
}
