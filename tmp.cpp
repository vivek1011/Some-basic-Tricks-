trie 
z algo
suffix array - freq of each string .
rmq.
kmp 
/*trie */
void insert(int n )
{
	int idx =0; int i ; 
	for(i = 31; i>=0; i--)
	{
		if((1<<i)&n)
		{
			if(t[idx][1]==-1)
			{
				t[idx][1] = size++;
			}
			idx = t[idx][1];
		}
		else
		{
			if(t[idx][0]==-1)
			{
				t[idx][0] = size++;
			}
			idx = t[idx][0]; 
		}
	}
}
int query(int n )
{
	int i , idx =0 , flag;
	int ans= 0;
	for(i = 31; i>=0; i--)
	{
		if( (1<<i) & n)
			flag=1;
		else
			flag=0;
		if(t[idx][1 - flag]!=-1)
		{
			ans = ans*2 + 1; 
			idx= t[idx][1-flag];
		}
		else 
		{
			ans = ans*2;
			idx = t[idx][flag];
		}
	}
	return ans;
}
/*
	suffix array - freq of each string 
*/
bool mycmp(struct s a , struct s b)
{
	return a.nr[0]==b.nr[0] ? (a.nr[1]<b.nr[1]?1:0) : (a.nr[0]<b.nr[0]?1:0);
}
void constructsa()
{
	for (int i = 0; i < n; ++i)
		P[0][i] = s[i] -'a';
	for (stp = 1, cnt=1; cnt<n ;cnt*=2,  ++stp)
	{
		for (int k = 0; k <n; ++k)
		{
			L[k].nr[0] = P[stp-1][k];
			L[k].nr[1] = k+cnt<n ? P[stp-1][k+cnt]:-1;
			L[k].p = k;
		}
		sort(L , L+n , mycmp);
		for (int i = 0; i < n; ++i)
		{
			P[stp][L[i].p] = i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]? P[stp][L[i-1].p] : i;
		}
	}
	for (int i = 0; i < n; ++i)
		sa[P[stp-1][i]] = i;
	return ;
}
int lcp(int i , int j)
{
	if(i==j)
		return n-i;
	int ans= 0;
	for (int k = stp-1; k>=0 && i<n && j<n; k--)
	{
		if(P[k][i]==P[k][j])
		{
			ll tempo = power(2, k );
			ans += tempo, i += tempo, j +=tempo;
		}
	}
	return ans;
}	
void constlcp()
{
	for (int i = 0; i < n-1; ++i)
	{
		LCP[i] = lcp(sa[i] , sa[i+1]);
		l[LCP[i]].pb(i);
	}
	return; 
}
void constleft()
{
	int top = 0;
	for(int i=0; i<n-1; i++) {
		while(top && LCP[stk[top-1]] >= LCP[i]) top--;
		if(top == 0) L1[i] = -1;
		else L1[i] = stk[top-1];
		stk[top++] = i;
	}
	top = 0;
	for(int i=n-2; i>=0; i--) {
		while(top && LCP[stk[top-1]] >= LCP[i]) top--;
		if(top == 0) R[i] = n-1;
		else R[i] = stk[top-1];	
		stk[top++] = i;
	}
	for(int i=n; i; i--) {
		int j = 0;
		while(j < l[i].size()) {
			int mini = i;
			int k = l[i][j];
			if(L1[k] != -1 && mini > i - LCP[L1[k]]) mini = i - LCP[L1[k]];
			if(R[k] != n-1 && mini > i - LCP[R[k]]) mini = i - LCP[R[k]];
			int range = R[k] - L1[k] - 1 + 1;
			D[range] += (long long)mini * range;
			while(j < l[i].size() && l[i][j] < R[k]) j++;
		}
	}
	for (int i = 1; i <=n; ++i)
	{
		D[i] = D[i]/i;
	}
/*
	D[i] represent the number of substrings which repeat exactly i times
*/
/*
	range minimum query 
*/
void fun()
{
    for(int i =1;i<=n;i++) m[i][0] = i ; 
    for(int j = 1; (1<<j)<=n;j++)
    {
        for(int i = 1; i+(1<<j)-1<=n;i++)   
        {
            if(a[m[i][j-1]] < a[m[i+(1<<(j-1))][j-1]])
                m[i][j] = m[i][j-1];
            else
               m[i][j] = m[i+(1<<(j-1))][j-1];  
        }
    }
    /*use*/
    cin>>l>>r;
    int k = log2(r-l+1);
    pos = a[m[l][k]] < a[m[r-(1<<k)+1][k]] ? m[l][k] : m[r-(1<<k)+1][k] ; 
}

/*kmp*/

void fun()
{
    int i = 1;
    int len = 0;  lps[0] =0 ;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i] = len ;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i] =0  ;
                i++;
            }
        }
    }
}
m = pat.size();
n = text.size(); 
fun(); 
int i =0 , j =0 ;
while(i<n)
{
    if(pat[j]==text[i]) 
    {
        i++;j++;
    }
    if(j==m)
    {
        cout<<"found at position "<<i-j<<endl;
        j = lps[j-1];
    }
    else if(i<n && pat[j]!=text[i])
    {
        if(j!=0)
            j = lps[j-1];
        else
            i++;
    }
}

/*z algo*/
void zfun()
{
	int i; 
	z[0] = 0 ; 
	n = s.size();
	int L = 0 , R= 0 ; 
	fl(i , 1, n)
	{
		if(i>R){
			L = R = i ; 
			while(R<n && s[R-L]==s[R]) R++; 
			z[i] = R-L ; R-- ;
		}
		else
		{
			int k= i -L; 
			if(z[k]<R-i+1){
				z[i] = z[k]; 
			}
			else{
				L= i ; 
				while(R<n && s[R-L]==s[R]) R++; 
				z[i] = R-L; R--; 
			}
		}
	}
}
