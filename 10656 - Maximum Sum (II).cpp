#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;

    while(N)
    {

        int seq[N];
        seq[0] = 0;
        int j = 0;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            if(x)
                seq[j++] = x;

        }
        cout<<seq[0];
        for(int i = 1;i<j;i++)
        {
            printf(" %d",seq[i]);
        }

        cout<<endl;
        cin>>N;
    }

}
