#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
using namespace std;
int primes[100005],myprimes[100005],a[100005];
int main()
{
 	int m,n,i,j,count=0,p,s,t;
 	cin>>t;
 	while(t--)
 	{	
	count=0;
	cin>>m>>n;
	fl(i,0,100002)
	a[i] =0;
	fl(i,0,100002)
	primes[i] = 1;
	int k = sqrt(sqrt(n));
	fl(i,2,k)
	{
		if(a[i]!=1)
		{
			for(j=i*i;j<=sqrt(n);j=j+i)
			a[j]=1;
		}
	}
	int check = sqrt(n);
	fl(i,2,check)
	{
		if(a[i]==0)
			myprimes[count++] = i;
	}
	for(i=0;i<count;i++)
	{
		p = myprimes[i];
		s = m/p;
		s = s*p;
		for(j=s;j<=n;j=j+p)
		{
			if(j<m)
			continue;
			else
			primes[j-m] = 0;
		}
	}
	for(i=0;i<count;i++)
	{
		if(myprimes[i]>=m && myprimes[i]<=n)
		cout<<myprimes[i]<<endl;
	}
	for(i=0;i<n-m+1;i++)
	{
		if(primes[i]==1 && (i+m)!=1)
		cout<<i+m<<endl;
	}
	cout<<endl;
}
	return 0;
}
 
