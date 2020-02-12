#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll N,e,M;

ll f(ll N,ll e, ll M)
{
	if(e == 1)
		return N%M;
	if(e == 0)
		return 1;
	
	ll resp = f(N,e/2,M);
	
	resp = (resp%M * resp%M)%M;
	
	if(e%2)
		resp = (resp%M * N%M)%M;
		
	return resp;
}

int main()
{
	
	char c;
	while(cin>>c)
	{
		string aux = "";
		while(c!='#')
		{
			aux += c;
			cin>>c;
		}
		
		int cont = 0,resp = 0;
		for(int i = aux.size()-1;i>=0;i--)
		{
			if(aux[i] == '1')
			{
				resp = (resp%131071 + f(2,cont,131071)%131071)%131071;
			}
			cont++;
		}
		if(!resp)
			printf("YES\n");
		else
			printf("NO\n");
	}
}	
