#include <bits/stdc++.h>

using namespace std;
int N,half;
int moedinhas[110];
int PD[110][50010];

int mindiff(int idx,int sum)
{
    if(idx == N)
        return abs(sum - (half-sum));
    if(PD[idx][sum]!=-1)
        return PD[idx][sum];
    int resp = min(mindiff(idx+1,sum),mindiff(idx+1,sum+moedinhas[idx]));
    return PD[idx][sum] = resp;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(PD,-1,sizeof PD);
        cin>>N;
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            cin>>moedinhas[i];
            sum+=moedinhas[i];
        }
        half = sum;
        cout<<mindiff(0,0)<<endl;
    }

}
