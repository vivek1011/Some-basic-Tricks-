// sp[] denotes the starting position and ep[] denotes the ending position(1 - indexed)
#include<bits/stdc++.h>
using namespace std;
#define fl(i ,a, b) for(i=a; i < b ;i++)
int a[1234567];
int sp[10002] , ep[10002];
std::vector<int> v;
int main()
{
	int i ,n ; 
	cin>>n;
	v.push_back(0);
	fl(i , 1, n+1) cin>>a[i];
	a[0] = -1; a[n+1] = -1;
	fl(i , 1, n+2)
	{
		while(a[i]<a[v.back()])
		{
			ep[v.back()] = i ;
			v.pop_back();
		}
		sp[i] = v.back();
		v.push_back(i);
	}
	fl(i , 1, n+1)
	{
		sp[i] = sp[i]+1;
		ep[i] = ep[i] - 1;
		cout<<sp[i]<<" "<<ep[i]<<endl;
	}
	return 0;	
}
