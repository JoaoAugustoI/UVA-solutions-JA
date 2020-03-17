#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,K;

    while(cin>>N>>K)
    {
        double A = 0;
        for(double i = N-K+1;i<=N;i++)
        {
            A+=(log(i)/log(10));
        }
        double B = 0;
        for(double i = K;i>=1;i--)
        {
            B+=(log(i)/log(10));
        }

        cout<<ceil(A-B)<<endl;

    }
}
