#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include<cmath>
using namespace std ;
const long int N=pow (2.0,25);
long int a[N];
long int col_sum;
int main()
{
    long long head, tail,freq ;
    long int i,k,n,counter=1000;
    for ( i = 0; i < N;i++)
    {
            a[i]=i+1;
    }
    for(n=1;n<=N;n*=2)
    {
        if(n>=pow(2.0,20))
            counter=10;
        else if(n>=pow(2.0,15))
            counter=100;
        else if(n>=pow(2.0,10))
            counter=1000;
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);
        for(k=0;k<counter;k++){
            col_sum=0;
            for (i = 0; i < n; i++)
            {
                col_sum +=a[i];
            }
        }
        QueryPerformanceCounter((LARGE_INTEGER *)&tail) ;
        cout <<(tail-head) * 1000.0 / freq/counter << endl;
    }
    return 0;
 }
