/*
    How to get the prime factorisation of all numbers upto 10^5 in a 2-D vector.  
*/
void sieve()
{
	int i , j ; 
	for(int i = 2; i*i<=MAX ; i++)
	{
		if(a[i]==0)
		{
			for(int j = i*i; j<=MAX; j+=i)
				a[j] = 1;
		}
	}
	a[0] = a[1] = 1;  
	for(i = 2; i*i<MAX; i++)
	{
		if(!a[i])
			v[i].pb(i);
		for(j = i*2; j<MAX; j+=i)
		{
			if(i*i<=j && !a[i])
				v[j].pb(i);
			if(i*i<j && !a[j/i])
				v[j].pb(j/i);
		}
	}
	fl(i ,2, MAX)
	{
		if(v[i].empty()) v[i].pb(i);
	}
	return ; 
}
