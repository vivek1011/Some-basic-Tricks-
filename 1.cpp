/*
	use this equation - 
	y - y1 = slope(x - x1); 
	slope = (y2-y1)/(x2-x1)
	calculate this value (y1-y)*(x2-x1) + (y2-y1)*(x-x1);
	and compare this value with respect to 0 and store it for all the thre edges.
	if these all bool values are equal, then the point lies inside the traingle . 
	a[0] , b[0] , a[1] , b[1] , a[2] , b[2] these are the three point coordinates of triangle 
	and px , py - coordinates of the point to be checked .
*/
int fun(int x, int y , int x1, int y1, int x2 ,int y2)
{
	return (y1-y)*(x2-x1) + (y2-y1)*(x-x1);
}
bool pointinsidetriangle()
{
	bool b1 , b2, b3;
	b1 = fun(px , py , a[0] , b[0] , a[1] , b[1]) < 0;
	b2 = fun(px , py, a[1] , b[1] , a[2] , b[2]) < 0;
	b3 = fun(px , py , a[2] , b[2] , a[0] , b[0]) < 0 ;
	return (b1==b2 && b2==b3);
}
/* now call the pointinsidetriangle function to check. */
