#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

double force(double a)

{

	double r ;

	r = -4*pow(a,3) + 4*a ;

	return r ;

}

double pe(double b)

{
	
	double p, q ;
	
	q = pow(b,2) - 1 ;
	
	p = q*q ;
	
	return p ; 

}

double ke(double c)

{

	double s ;
	
	s = 0.5 * s * s ;
	
	return s ;
	
}

int main()

{

	ofstream fout("rk2-phase space.txt");

	double x0, v0, x, v, t1, t2, h, k1, k2;
	
	int i, n ;
	
	x0 = 1.0 ;
	
	v0 = 0.1 ;
	
	t1 = 0.0 ;
	
	t2 = 10.0 ;
	
	h = 0.001 ;
	
	n = (int)((t2 - t1) / h);
	
	fout << x0 << "\t" << v0 <<"\n";

	for(i=1;i<=n;i++)

	{

		
		k1 = force(x0) ;
		
		k2 = force(x0 + h * k1) ;

		v = v0 + h * ((k1 + k2)/2.0);

		x = x0 + v * h;
		
		v0 = v ;
		
		x0 = x ;
		
		fout << x0 << "\t" << v0 <<"\n";

	}

	fout.close();

	return 0;

}

