//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;
#define w(t) while(t--)
#define S(x) scanf("%d",&x)
#define SLL(x) scanf("%lld",&x)
#define P(x) printf("%d",x)
#define fl(i , a, b) for(i = (int)a; i<(int)b; i++)
#define mem(a , value) memset(a , value , sizeof(a))
#define tr(c, itr) for(itr = (c).begin(); itr != (c).end(); itr++)
#define MOD 1000000007
#define MAX 1000000010
#define ll long long
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
typedef pair<int,int> pp;
int a[1234567];
int n ; 
int bit[1000002];
int get(int idx)
{
    int ans =0 ; 
    while(idx > 0)
    {
        ans+= bit[idx];
        idx -= (idx & -idx);
    }
    return ans ;
}
void upd(int idx)
{
    while(idx <=n)
    {
        bit[idx]++;
        idx+= (idx & -idx); 
    }
}
int main()
{
    //std::ios_base::sync_with_stdio(false);
    int t , ans =0 , i , f ;  
    cin >> t;
    w(t){
        cin >> n ;
        mem(bit, 0 );
        ans= 0 ; 
        fl(i  ,1, n+1){
            cin >> a[i] ; 
        }
        f=0;
        for(i = n ; i >= 1; i--)
        {
            ans+= get(a[i]) ;
            upd(a[i]); 
        }
        cout << ans << endl; 
    }
    return 0;
}
