for two pointers sliding window basic procedure is
for finding out maximum size 
left =0 ; right =0 ; 
while(left < n && right < n )
{
  if(condition statisfied)
    increment value of right ;
  else
    increment left; 
  right = max(right , left); 
}


//erases all duplicate elements from the vector. 
#define all(v) v.begin(),v.end()
v.erase( unique(all(v)) , v.end()) ; 

// string to ll or integer;
string s;
ll n = atoll(s);  // similarly atoi (string to integer .)
cout << n << endl; 
