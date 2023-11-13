#include<iostream>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>

#define n 20000

#define m 200

using namespace std;

int main()

{
    double t[n], x[n], y[n], r[n], vx[n], vy[n], gx[n], gy[n];
    
    double h, h2, k = 39.478428, r2, r3;
    
    int i;
    
    ofstream fout("md_comet.dat");
    
    t[0] = 0.0;
    
    x[0] = 1.966843;
    
    y[0] = 0.0;
    
    r[0] = x[0];
    
    vx[0] = 0.0;
    
    vy[0] = 0.815795;
    
    gx[0] = -k / ( r[0] * r[0] );
    
    gy[0] = 0.0;
    
    h = 2.0 / ( n - 1);
    
    h2 = (h * h ) / 2.0;
    
    for ( i = 0 ; i < n-1 ; i++ )
    
    {
      
      t[i+1] = h * (i+1);
      
      x[i+1] = x[i] + (h * vx[i]) + (h2 * gx[i]);
      
      y[i+1] = y[i] + (h * vy[i]) + (h2 * gy[i]);
      
      r2 = (x[i+1] * x[i+1]) + (y[i+1] * y[i+1]);
      
      r[i+1] = sqrt(r2);
      
      r3 = r2 * r[i+1];
      
      gx[i+1] = (-k * x[i+1]) / r3;
      
      gy[i+1] = (-k * y[i+1]) / r3;
      
      vx[i+1] = vx[i] + (h * (gx[i+1] + gx[i]) / 2.0 );
      
      vy[i+1] = vy[i] + (h * (gy[i+1] + gy[i]) / 2.0 );
     
    }
    
    for ( i = 0 ; i < n-m ; i = i + m )
    
    {
      
      fout << t[i] << "\t" << r[i] <<"\n";
    
    }
    
    fout.close();
    
    return 0;

}
