#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in","r",stdin);
    map<int,string> mp;
    mp[1] = "DEFICIENT";
    for(long long int i = 2;i<=60000;i++)
    {
        int sum = 1;
        for(long long int j = 2;j*j<=i;j++)
        {
            if(i%j == 0)
            {
                if(j*j<i)
                {
                    sum+=j+(i/j);
                }
                else
                {
                    sum+=j;
                }

            }
        }
        if(sum == i)
        {
            mp[i] = "PERFECT";
        }
        if(sum < i)
        {
            mp[i] = "DEFICIENT";
        }
        if(sum > i)
        {
            mp[i] = "ABUNDANT";
        }
    }

    int N;
    vector<int> vet;
    cin>>N;
    while(N)
    {
        vet.push_back(N);
        cin>>N;
    }
    cout<<"PERFECTION OUTPUT"<<endl;
    for(int i = 0;i<vet.size();i++)
    {
        cout<<setw(5);
        cout<<vet[i]<<"  "<<mp[vet[i]]<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
}
