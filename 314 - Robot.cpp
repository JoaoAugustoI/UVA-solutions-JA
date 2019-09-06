#include <bits/stdc++.h>
using namespace std;

int mat[55][55],startX,startY,endX,endY,direcao;
map<pair<pair<int,int>,int>,int> mapa;
int L,C;
string dir;

void setdir(string x)
{
    if(x == "south")
        direcao = 2;
    if(x == "north")
        direcao = 0;
    if(x == "west")
        direcao = 3;
    if(x == "east")
        direcao = 1;
}

int qtdvira(int d,int nvd)
{
    int x = d - nvd;
    if(abs(x) == 2)
        return 2;
    else
        return 1;
}

bool arealimpa(int x,int y)
{
    if(x<=0 or x>=L or y<=0 or y>=C)
        return false;
    if(mat[x][y])
        return false;
    if(mat[x-1][y-1])
        return false;
    if(mat[x-1][y])
        return false;
    if(mat[x][y-1])
        return false;
    return true;
}

int bfs()
{
    setdir(dir);
    queue<pair<pair<int,int>,int> > kiwi;
    mapa[make_pair(make_pair(startX,startY),direcao)] = 0;
    kiwi.push(make_pair(make_pair(startX,startY),direcao));
    //int l = 1;
    while(kiwi.size())
    {

        int x = kiwi.front().first.first,y = kiwi.front().first.second, d = kiwi.front().second;
        kiwi.pop();
        //printf("%d = (%d,%d) direcao = %d dist = %d\n",l++,x,y,d,mapa[make_pair(make_pair(x,y),d)]);
        if(x == endX and y == endY)
        {
            return mapa[make_pair(make_pair(x,y),d)];
        }

        if(d == 0 and arealimpa(x-1,y) and mapa.find(make_pair(make_pair(x-1,y),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x-1,y),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x-1,y),d));
        }
        if(d == 0 and arealimpa(x-1,y) and arealimpa(x-2,y) and mapa.find(make_pair(make_pair(x-2,y),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x-2,y),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x-2,y),d));
        }
        if(d == 0 and arealimpa(x-1,y) and arealimpa(x-2,y) and arealimpa(x-3,y) and mapa.find(make_pair(make_pair(x-3,y),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x-3,y),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x-3,y),d));
        }
        if(d == 1 and arealimpa(x,y+1) and mapa.find(make_pair(make_pair(x,y+1),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y+1),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y+1),d));
        }
        if(d == 1 and arealimpa(x,y+1) and arealimpa(x,y+2) and mapa.find(make_pair(make_pair(x,y+2),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y+2),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y+2),d));
        }
        if(d == 1 and arealimpa(x,y+1) and arealimpa(x,y+2) and arealimpa(x,y+3) and mapa.find(make_pair(make_pair(x,y+3),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y+3),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y+3),d));
        }
        if(d == 2 and arealimpa(x+1,y) and mapa.find(make_pair(make_pair(x+1,y),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x+1,y),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x+1,y),d));
        }
        if(d == 2 and arealimpa(x+1,y) and arealimpa(x+2,y) and mapa.find(make_pair(make_pair(x+2,y),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x+2,y),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x+2,y),d));
        }
        if(d == 2 and arealimpa(x+1,y) and arealimpa(x+2,y) and arealimpa(x+3,y) and mapa.find(make_pair(make_pair(x+3,y),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x+3,y),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x+3,y),d));
        }
        if(d == 3 and arealimpa(x,y-1) and mapa.find(make_pair(make_pair(x,y-1),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y-1),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y-1),d));
        }
        if(d == 3 and arealimpa(x,y-1) and arealimpa(x,y-2) and mapa.find(make_pair(make_pair(x,y-2),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y-2),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y-2),d));
        }
        if(d == 3 and arealimpa(x,y-1) and arealimpa(x,y-2) and arealimpa(x,y-3) and mapa.find(make_pair(make_pair(x,y-3),d))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y-3),d)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y-3),d));
        }
        
        //esquerda
        int k = d-1;
        if(k == -1) k = 3;
        if(mapa.find(make_pair(make_pair(x,y),k))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y),k)] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y),k));
        }
        //direita
        if(mapa.find(make_pair(make_pair(x,y),((d+1)%4)))==mapa.end())
        {
            mapa[make_pair(make_pair(x,y),((d+1)%4))] = mapa[make_pair(make_pair(x,y),d)]+1;
            kiwi.push(make_pair(make_pair(x,y),((d+1)%4)));
        }
    }
    return -1;
}



int main()
{
	//freopen("in","r",stdin);
    //freopen("out","w",stdout);
    cin>>L>>C;
    
    while(L and C)
    {
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<C;j++)
            {
                cin>>mat[i][j];
            }
        }
        cin>>startX>>startY>>endX>>endY>>dir;
        if(!arealimpa(startX,startY) or !arealimpa(endX,endY))
            cout<<-1<<endl;
        else
        {
            cout<<bfs()<<endl;
        }
        mapa.clear();
        cin>>L>>C;
    }
}
