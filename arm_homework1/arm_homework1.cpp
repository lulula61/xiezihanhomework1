#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std ;
double *a,**b,*sum;
int i,j,k,n,step=1,counter=100000;
void common()
{
    for (i = 0; i < n; i++) {
        sum[ i ] = 0.0;
        for ( j = 0; j < n; j++)
            sum[ i ] += b[ j ] [ i ] *a[j];
    }
}
void cache()
{

    for (i = 0; i < n; i++)
        sum[ i ] = 0.0;
    for ( j = 0; j < n; j++)
        for(i=0;i<n;i++)
            sum[ i ] += b[ j ] [ i ] *a[j];
}
int main()
{
    cout<<"Common:"<<endl;
    double time_use=0;
    struct timeval head;
    struct timeval tail;
    bool optimize=false;
    for(n=1;n<=10000;n+=step)
    {
        if(n==10)
            {step=10;counter=1000;}
        if(n==100)
            {step=100;counter=10;}
        if(n==1000)
            {step=1000;counter=5;}
        a=new double[n];
        b=new double*[n];
        sum=new double[n];
        for(i=0;i<n;i++)
            b[i]=new double[n];
        for ( i = 0; i < n; i++)
        {
            a[i]=i;
            for ( int j = 0; j < n; j++)
                b[ i ] [ j ] = i + j ;
        }
        gettimeofday(&head,NULL);  //start time
        for( k=0;k<counter;k++){
            if(optimize==false)
                common();
            else
                cache();
        }
        // end time
        gettimeofday(&tail,NULL);
        time_use=(tail.tv_sec-head.tv_sec)*1000.0+(tail.tv_usec-head.tv_usec)/1000.0;
        cout << time_use/counter << endl;
        delete[]a;
        delete[]sum;
        for(i=0;i<n;i++)
            delete[]b[i];
        delete[]b;
        if(n==10000&&optimize==false)
        {
            optimize=true;
            n=0;
            step=1;
            counter=100000;
            cout<<"Cache:"<<endl;
        }
    }
    return 0;
 }
