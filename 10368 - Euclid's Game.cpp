#include <bits/stdc++.h>

using namespace std;
map<pair<int,int>,int> PD;
bool jogo(int a,int b)
{
    if(b>a)
    {
        int aux = a;
        a = b;
        b = aux;
    }
    if(b == 0)
    {
        return false;
    }
    if(PD.count(make_pair(a,b)))
    {
        return PD[make_pair(a,b)];
    }
    bool flag = true;
    flag &= jogo(b,a%b);
    if((a%b+b) != a)
        flag &= jogo(b,a%b+b);

    return PD[make_pair(a,b)] = !flag;
}
int main()
{
    int ini,cio;
    cin>>ini>>cio;
    while(ini and cio)
    {
        if(jogo(ini,cio))
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
        cin>>ini>>cio;
    }
}

