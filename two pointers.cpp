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
