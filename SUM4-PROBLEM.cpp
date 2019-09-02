#include <bits/stdc++.h>

using namespace std;

//o problema da soma de dois valores adaptado para 4 valores
//problema original: Seja L um vetor de inteiros. Determine se existem dois elementos distintos x e y em L, tal que x+y = K.

vector <int> v;
int pick_i = -1;
int pick_j = -1;

bool sum2(int n, int K, int &x, int &y)
{
    int i,j;
    i = 0;
    j = n-1;
    while(i<j)
    {
        if(pick_j == j or v[i]+v[j] > K ) j--;
        if(pick_i == i or v[i]+v[j] < K ) i++;
        if(pick_i != i and pick_j != j and v[i]+v[j] == K and i!=j)
        {
            x = v[i];
            y = v[j];
            pick_i = i;
            pick_j = j;
            return true;
        }
    }
    return false;
}

bool sum4(int n, int K,int &w,int &x, int &y, int &z)
{
    for(int i = 0; i <= K/2;i++)
    {
        if(sum2(n,i,w,x) and sum2(n,K-i,y,z))
        {
            return true;
        }
        pick_i = -1;
        pick_j = -1;
    }
    return false;
}

int main()
{
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    sort(v.begin(),v.end());

    int w,x,y,z,sum;
    sum = 10;

    for(int i=0;i<20;i++)
    {
        sum = i;
        if(sum4(v.size(),sum,w,x,y,z))
        {
            printf("%d + %d + %d + %d = %d\n",w,x,y,z,sum);
        }
        else
        {
            printf("num vai dah nao!!!\n");
        }
    }


}

