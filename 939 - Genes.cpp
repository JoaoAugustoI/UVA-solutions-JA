#include <bits/stdc++.h>
using namespace std;


string genret(int a, int b)
{
    int x = a+b;
    if(x>0)
        return "dominant";
    if(!x)
        return "recessive";
    if(x<0)
        return "non-existent";
    return "fudeu!";
}

int main()
{
    int N;
    map <string,vector<string> > paisefilhos;
    map <string,string> gene;
    unsigned int cont = 0;
    cin>>N;

    while(N--)
    {
        string aux1,aux2;

        cin>>aux1>>aux2;

        if(aux2 != "dominant" and aux2 != "recessive" and aux2 != "non-existent")
        {
            if(!paisefilhos[aux2].size())
                cont++;
            paisefilhos[aux2].push_back(aux1);

        }
        else
        {
            cont++;
            gene[aux1] = aux2;
        }
    }

    while(gene.size()<cont)
    {
        for(map <string,vector<string> >::iterator it = paisefilhos.begin();it!=paisefilhos.end();it++)
        {
            if(gene.find(it->second[0])!=gene.end() and gene.find(it->second[1])!=gene.end())
            {
                int a = 0,b = 0;
                if(gene[it->second[0]] == "dominant")
                    a = 1;
                if(gene[it->second[0]] == "non-existent")
                    a = -1;
                if(gene[it->second[1]] == "dominant")
                    b = 1;
                if(gene[it->second[1]] == "non-existent")
                    b = -1;
                gene[it->first] = genret(a,b);
            }
        }
    }

    for(map<string,string>::iterator it = gene.begin();it!=gene.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}
