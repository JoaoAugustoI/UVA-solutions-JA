#include <bits/stdc++.h>
#define LL long long int
using namespace std;

vector<LL> primos;
bitset<32767> bs;

void crivo()
{
    bs.set();
    bs[0] = bs[1] = 0;
    for(LL i = 2;i<=32767;i++)
    {
        if(bs[i])
        {
            primos.push_back(i);
            for(LL j = i*i;j<=32767;j+=i)
                bs[j] = 0;
        }
    }
}

int main()
{
    crivo();
    string s;
    getline(cin,s);
    while(s!="0")
    {
        vector<int> fac;
        stringstream st(s);

        int a;
        while(st>>a)
        {
            fac.push_back(a);
        }

        LL mul = 1;
        for(int i = 1;i<(int)fac.size();i+=2)
        {
                mul *= pow(fac[i-1],fac[i]);
        }

        mul--;
        vector <int> resp;
        for(int i = 0;i<(int)primos.size() and mul>1;i++)
        {
            int cont = 0;
            int pr = primos[i];
            if(mul%pr == 0)
            {
                while(mul%pr == 0)
                {
                    mul/=pr;
                    cont++;
                }
                resp.push_back(cont);
                resp.push_back(pr);
            }
        }

        if(mul>1)
        {
            resp.push_back(1);
            resp.push_back(mul);
        }
        cout<<resp[resp.size()-1];
        for(int i = resp.size()-2;i>=0;i--)
        {
            cout<<" "<<resp[i];
        }
        puts("");
        getline(cin,s);
    }
}
