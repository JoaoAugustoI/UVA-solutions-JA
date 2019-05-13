#include <bits/stdc++.h>

using namespace std;

int main()
{
    string aux;


    cin>>aux;
    while(aux!="#")
    {
        if(next_permutation(aux.begin(),aux.end()))
        {
            cout<<aux<<endl;
        }
        else
        {
            cout<<"No Successor"<<endl;
        }
        cin>>aux;
    }
}
