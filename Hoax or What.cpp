#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N)
    {
        long long int S = 0;
        map<int,int> bills;
        while(N--)
        {
            int K;
            cin>>K;
            for(int i=0;i<K;i++)
            {
                int aux;
                cin>>aux;
                bills[aux]++;
            }
            long long int payday = 0;
            map<int,int>::iterator it = bills.begin();
            while(!bills[it->first] and it != bills.end())
            {
                int aux = it->first;
                it++;
                bills.erase(aux);

            }

            if(bills[it->first])
            {
                payday = bills[it->first];
                bills[it->first]--;
            }

            payday = it->first;
            it = bills.end();
            it--;
            while(!bills[it->first] and it != bills.begin())
            {
                int aux = it->first;
                it--;
                bills.erase(aux);

            }

            if(bills[it->first])
            {
                payday = abs(payday-it->first);
                bills[it->first]--;
            }
            S += payday;
        }
        cout<<S<<endl;
        cin>>N;
    }

}
