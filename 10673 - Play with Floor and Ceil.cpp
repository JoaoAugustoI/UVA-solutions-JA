#include <bits/stdc++.h>

using namespace std;

#define ll long long int 

long long int X,Y,d;

void euclidao(long long int a,long long int b)
{
	if(b == 0)
	{
		X = 1;Y = 0;d = a;return;
	}
	euclidao(b,a%b);
	long long int  x1 = Y;
	long long int  y1 = X - (a/b)*Y;
	
	X = x1;
	Y = y1;
}

int main()
{
	long double P,Q,x,k;
	long long int t;
	cin>>t;
	
	while(t--)
	{
		cin>>x>>k;
		P = Q = x/k;
		P = floor(P);
		Q = ceil(Q);
		euclidao(P,Q);
		long long int  m = x/d;
		cout<<X*m<<" "<<Y*m<<endl;
	}
	
	
	
}
