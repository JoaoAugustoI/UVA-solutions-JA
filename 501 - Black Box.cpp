#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,N,M;
    cin>>T;
    bool flag = false;
    while(T--)
    {
        queue <int> get,add;
        cin>>N>>M;

        for(int i=0;i<N;i++)
        {
            int aux;
            cin>>aux;
            add.push(aux);
        }

        for(int i=0;i<M;i++)
        {
            int aux;
            cin>>aux;
            get.push(aux);
        }

        multiset<int> blackbox;
        multiset<int>::iterator it;
        if(flag)
            cout<<endl;
        flag = true;
        int i = 0;
        while(get.size())
        {
            if(blackbox.size()<get.front())
            {
                blackbox.insert(add.front());
                add.pop();
            }
            else
            {
                int k = blackbox.size()/2;
                if(i<=k)
                {
                    int j = 0;
                    for(it = blackbox.begin();j<i;j++,it++);
                }
                else
                {
                    int n = blackbox.size();
                    for(it = blackbox.end();n>i;n--,it--);
                }
                cout<<*it<<endl;
                i++;
                get.pop();
            }
        }
    }
}
