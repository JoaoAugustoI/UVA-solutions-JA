#include <bits/stdc++.h>

using namespace std;

int main()
{
	int vet[101];
	
	string s;
	
	int N;
	cin>>N;
	cin.ignore();
	while(N--)
	{
		getline(cin,s);
		stringstream st(s);
		int i = 0;
		while(st>>vet[i++]);
	}
}
