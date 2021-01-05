#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int coins[5] = {1,5,10,25,50};

    int count[7490];

    count[0] = 1;
    for(int i = 1;i<7490;i++)
        count[i] = 0;
    for(int c : coins)
    {
        for(int x = 1;x <= 7489; x++)
        {
            if(x-c >= 0)
            {
                count[x] += count[x-c];
            }
        }
    }
    while(cin>>N)
    {

        cout<<count[N]<<endl;
    }
}
