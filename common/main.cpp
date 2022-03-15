#include <iostream>
#include <windows.h>
#include<stdlib.h>

using namespace std ;
int main()
{


    long long head, tail , freq ;
    int i,j,k,n,step=1,counter=100000;
    for(n=2;n<=10000;n+=step)
    {
        if(n==10)
            {step=10;counter=1000;}
        if(n==100)
            {step=100;counter=100;}
        if(n==1000)
            {step=1000;counter=10;}
        double *a=new double[n],**b=new double*[n],*col_sum=new double[n];
        for(i=0;i<n;i++)
            b[i]=new double[n];
        for ( i = 0; i < n; i++)
        {
            a[i]=i;
            for ( int j = 0; j < n; j++)
                b[ i ] [ j ] = i + j ;
        }
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq ) ;
        // start time
        QueryPerformanceCounter((LARGE_INTEGER* )&head) ;
        for( k=0;k<counter;k++){
            for (i = 0; i < n; i++) {
                col_sum[ i ] = 0.0;
            for ( j = 0; j < n; j++)
                col_sum[ i ] += b[ j ] [ i ] *a[j];
            }
        }
        // end time
        QueryPerformanceCounter((LARGE_INTEGER *)&tail ) ;
        cout << (tail-head) * 1000.0 / freq/counter << endl;
        delete[]a;
        delete[]col_sum;
        for(i=0;i<n;i++)
            delete[]b[i];
        delete[]b;
    }
    return 0;
 }
