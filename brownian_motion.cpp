#include<fstream>
#include<iostream>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
#include<math.h>
#define N 100
using namespace std;

int main()
{
	ofstream filout("brownian.dat");
	double x[N],y[N],R=0.0,s,a,b,c,d,meanfreepath;
	int i;
	x[0]=0.0;
	y[0]=0.0;
	a=x[0];
	b=y[0];
	filout<<x[0]<<"   "<<y[0]<<"\n";
	srand(time(NULL));
	cout<<"Position of particles"<<"\n";
	for(i=1;i<=N;i++)
	  {
		  x[i]=(double)rand()/(RAND_MAX);
		  y[i]=(double)rand()/(RAND_MAX);
		  c=x[i]-a;
		  d=y[i]-b;
		  s=c*c+d*d;
		  R=R+sqrt(s);
		  filout<<x[i]<<"   "<<y[i]<<"\n";
	  }   
    meanfreepath=R/N;
    cout<<"The Mean free path is = "<<meanfreepath;
	filout.close();
    return 0;
}

