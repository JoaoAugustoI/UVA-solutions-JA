#include <bits/stdc++.h>

using namespace std;

int main()
{
    double v,c,s;

    while(cin>>v>>c>>s)
    {
        cout<<fixed;
        cout.precision(5);
        cout<<((v/(v+c))*(c/(c+v-s-1)))+((c/(v+c))*((c-1)/(v+c-s-1)))<<endl;
    }
}
