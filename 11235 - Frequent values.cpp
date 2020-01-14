#include <bits/stdc++.h>

using namespace std;


int vet[1000010];
struct info
{
    int qt = -1;
    int ve = -100001;
    int vd = -100001;
    int qe = 0;
    int qd = 0;
};
info st[4000010];

info merge(info a, info b)
{
    info c;
    c.ve = a.ve;
    c.vd = b.vd;
    if(a.qt == -1)
        return b;
    if(b.qt == -1)
        return a;
    if(a.ve == b.ve)
    {
        c.qe = a.qe + b.qe;
    }
    else
    {
        c.qe = a.qe;
    }

    if(a.vd == b.vd)
    {
        c.qd = a.qd + b.qd;
    }
    else
    {
        c.qd = b.qd;
    }

    if(a.vd == b.ve)
    {
        c.qt = max(a.qd+b.qe,max(a.qt,b.qt));
    }
    else
    {
        c.qt = max(a.qt,b.qt);
    }
    return c;
}

info build(long long int P,long long int l,long long int r)
{
    if(l==r)
    {
        st[P].qt = 1;
        st[P].qe = 1;
        st[P].qd = 1;
        st[P].ve = vet[l];
        st[P].vd = vet[l];
        return st[P];
    }
    info P1 = build(2*P,l,(r+l)/2);
    info P2 = build(2*P+1,((r+l)/2)+1,r);
    return st[P] = merge(P1,P2);
}



info query(long long int P,long long int i,long long int j,long long int l, long long int r)
{
    if(i>r or j<l)
        return info();
    if(i<=l and r<=j)
        return st[P];
    info P1 = query(2*P,i,j,l,(r+l)/2);
    info P2 = query(2*P+1,i,j,(l+r)/2+1,r);
    return merge(P1,P2);
}


int main()
{
    int N;
    cin>>N;

    while(N)
    {
        int Q;
        cin>>Q;

        for(int i = 1;i<=N;i++)
            cin>>vet[i];
        build(1,1,N);
        while(Q--)
        {
            int i,j;
            cin>>i>>j;

            cout<<query(1,i,j,1,N).qt<<endl;
        }
        cin>>N;

    }
}
