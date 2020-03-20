#include <bits/stdc++.h>

using namespace std;
int vetUP[10000100];
int vetDOWN[10000100];
int main()
{
    int NextUP = 1;
    int NextDOWN = 2;
    int contUP = 1,contDOWN = 1;
    bool flagUP = false,flagDOWN = false;
    for(int i = 1;i<=10000099;i++)
    {
        vetUP[i] = contUP;
        if(NextUP == contUP)
        {
            NextUP+=2;
            flagUP = true;
        }
        if(!flagUP)
            contUP++;
        else
        {
            if(contUP>1)
                contUP--;
            else
                flagUP = false;
        }

        vetDOWN[i] = contDOWN;
        if(NextDOWN == contDOWN)
        {
            NextDOWN+=2;
            flagDOWN = true;
        }
        if(!flagDOWN)
            contDOWN++;
        else
        {
            if(contDOWN>1)
                contDOWN--;
            else
                flagDOWN = false;
        }
    }
    int N;
    while(cin>>N)
    {
        printf("TERM %d IS %d/%d\n",N,vetUP[N],vetDOWN[N]);
    }

}
