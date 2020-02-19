#include <bits/stdc++.h>

using namespace std;

vector<long long int> primos;
int dI,dJ;
bool twosum(int i,int j,int N)
{
    while(i<=j)
    {
        if(primos[i]+primos[j] > N)
            j--;
        if(primos[i]+primos[j] < N)
            i++;
        if(primos[i]+primos[j] == N)
        {
            dI = i;
            dJ = j;
            return true;
        }
    }
    return false;
}
int main()
{
    bitset<1000010> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long int i = 2;i<=1000010;i++)
    {
        if(bs[i])
        {
            primos.push_back(i);
            for(long long int j = i*i;j<=1000010;j+=i)
                bs[j] = 0;
        }
    }
    int N;
    cin>>N;
    while(N)
    {
        int i = 0;
        while(primos[i]<N and i<primos.size())
        {
            i++;
        }
        if(i>0)
            i--;
        if(twosum(0,i,N))
        {
            printf("%d = %d + %d\n",N,primos[dI],primos[dJ]);
        }
        else
        {
            printf("Goldbach's conjecture is wrong.\n");
        }

        cin>>N;
    }



}
