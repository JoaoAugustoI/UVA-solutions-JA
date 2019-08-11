#include <bits/stdc++.h>

using namespace std;

const int numbers = 10;
struct trie
{
    struct trie *Numeros[numbers];
    bool leaf;
};

struct trie *novo()
{
    struct trie *novoNo = new trie;
    novoNo->leaf = false;

    for(int i=0;i<numbers;i++)
    {
        novoNo->Numeros[i] = NULL;
    }
    return novoNo;
}

void insert(struct trie *root,string telefone)
{
    struct trie *descida = root;

    for(int i=0;i<telefone.size();i++)
    {
        int idx = telefone[i] - '0';
        if(!descida->Numeros[idx])
            descida->Numeros[idx] = novo();
        descida = descida->Numeros[idx];
    }
    descida->leaf = true;
}

bool valida(struct trie *root,string telefone)
{
    struct trie *descida = root;
    int idx;
    for(int i=0;i<telefone.size();i++)
    {
        idx = telefone[i] - '0';
        if(descida->leaf and descida->Numeros[idx])
            return 0;
        descida = descida->Numeros[idx];
    }
    return true;
}

int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        struct trie *Root = novo();
        cin>>N;
        string lista[N];
        for(int i=0;i<N;i++)
        {
            cin>>lista[i];
            insert(Root,lista[i]);
        }

        sort(lista,lista+N);
        bool flag = true;
        for(int i=0;i<N;i++)
        {
            flag = valida(Root,lista[i]);
            if(!flag)
                i = N;
        }

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
