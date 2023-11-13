#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 10000000

using namespace std ;

int main()
{

        srand(time(NULL)) ;

        int prize, first_choice, count1 = 0, count2 = 0 ;

        double p1, p2 ;

        for (int i = 1 ; i <= N ; i++)

        {
                
                prize = (rand() % 1000) + 1 ;

                first_choice = (rand() % 1000) + 1 ; 

                if (first_choice == prize)

                {

                        count1++ ; 

                }
                

                else

                {

                        count2++ ;

                }

        }

        p1 = ((double)count1 / N) * 100.0 ;

        p2 = ((double)count2 / N) * 100.0 ; 

        cout << count1 << "\t" << count2 << "\t" << p1 << "\t" << p2 << "\n" ;

        return 0;

}
