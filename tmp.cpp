LUCA'S THEOREM  : : : -- 

ll pow_mod(ll a,ll b)
{
    ll x=1;
    while(b)
    {
        if(b&1) 
            x=(x*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return x;
} 

ll ans(ll n ,ll m)
{
    ll i,t=min(n,m),numerator=1,denominator=1;
    
    for(i=0;i<t;i++)
    {
        numerator=(numerator*(n-i))%M;
        denominator=(denominator*(t-i))%M;
    }
    return ((numerator)*pow_mod(denominator,1000001))%M;
}
 
ll Lucas(ll n,ll m)
{
    if (n==0&&m==0) 
        return 1;
    
    if (m%M>n%M)
        return 0;
    
    return ((Lucas(n/M,m/M))%M*ans(n%M,m%M))%M;
}


Chinese Remainder Theorem : : : --

/ returns x where (a * x) % b == 1
int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
 
int chinese_remainder(int *n, int *a, int len)
{
	int p, i, prod = 1, sum = 0;
 
	for (i = 0; i < len; i++) prod *= n[i];
 
	for (i = 0; i < len; i++) {
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}
 
	return sum % prod;
}


/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main(void)
{
	int n[] = { 3, 5, 7 };
	int a[] = { 2, 3, 2 };
 
	printf("%d\n", chinese_remainder(n, a, sizeof(n)/sizeof(n[0])));
	return 0;
}


sigma (r to n ) ( ncr(i,r) ) = ncr(n+1,r+1)
sigma (0 to r ) ( ncr(m,k)*ncr(n,r-k) )  = ncr(m+n,r) 
 
V-E+F=2

Fibonacci identities - 

sigma (F i ) form 1 to n = 	(F  n+2) -1
sigma (F i )^2 = (F n)*(F n+1)

sigma ( gcd(i,n) ) (from 1 to n) = sigma (d*phi(n,d) ) such that d is a divisor of n

sigma ( phi(d) ) = n such that d is a divisor of n

The number of representations of a natural number n as the sum of 4 squares  is denoted by 8*sigma(m) if n is odd and 24*sigma(m m is odd) when n is even ... here m is a divisor of n ...
