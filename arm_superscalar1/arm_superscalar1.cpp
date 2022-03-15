#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include<cmath>
using namespace std ;
const long int N=pow (2.0,25);
long int a[N];
long int sum,sum1,sum2;
int main()
{
    double time_use=0;
    struct timeval head;
    struct timeval tail;
    long int i,k,n,counter=1000;
    for ( i = 0; i < N;i++)
    {
            a[i]=i+1;
    }
    for(n=2;n<=N;n*=2)
    {
        if(n>=pow(2.0,20))
            counter=10;
        else if(n>=pow(2.0,15))
            counter=100;
        else if(n>=pow(2.0,10))
            counter=1000;
        gettimeofday(&head,NULL);  //start time
        for(k=0;k<counter;k++){
            sum1=0;
            sum2=0;
            for (i = 0; i < n; i+=2) //¶àÁ´Â·Ê½
            {
                sum1 +=a[i];
                sum2+=a[i+1];
            }
            sum=sum1+sum2;
        }
        // end time
        gettimeofday(&tail,NULL);
        time_use=(tail.tv_sec-head.tv_sec)*1000.0+(tail.tv_usec-head.tv_usec)/1000.0;
        cout << time_use/counter << endl;
    }
    return 0;
 }
