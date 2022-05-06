#include <bits/stdc++.h>

using namespace std;

int row[8], TC, a, b, lineCounter;
vector<char> vertices;
map<char, vector<char> > adjlist;
map<char,bool> visitados;

bool place(char v)
{
    for(unsigned int k=0;k<adjlist[v].size();k++)
    {
        if(visitados[adjlist[v][k]])
           return false;
    }
    return true;
}

bool flag2 = false;
void backtrack(string ordem)
{
    if (ordem.size() == vertices.size())
    {
        flag2 = true;
        cout<<ordem[0];
        
        for (unsigned int j = 1; j < ordem.size(); j++)
            cout<<" "<<ordem[j];
        cout<<endl;
    }
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if(!visitados[vertices[i]] and place(vertices[i]))
        {
            visitados[vertices[i]] = true;
            backtrack(ordem + vertices[i]);
            visitados[vertices[i]] = false;
        }
    }
}



int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int N;
    cin>>N;
    bool flag = false;
    cin.ignore();
    while(N--)
    {
        cin.ignore();
        if(flag)
            cout<<endl;
        flag = true;

        string X;
        getline(cin,X);

        for(unsigned int i=0;i<X.size();i++)
        {
            if(X[i]!=' ')
            {
                vertices.push_back(X[i]);
                visitados[X[i]] = false;
            }
        }

        getline(cin,X);

        for(unsigned int i=0;i<X.size();i++)
        {
            if(X[i] == '<')
            {
                adjlist[X[i-1]].push_back(X[i+1]);
            }
        }

        backtrack("");
        if(!flag2)
        {
            cout<<"NO"<<endl;
        }
        flag2 = false;
        adjlist.clear();
        vertices.clear();
        visitados.clear();
    }
}
