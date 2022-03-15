#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include<cmath>
using namespace std ;
const long int N=pow (2.0,25);
long int a[N];
long int sum;
void f(int n)
{
    if(n==1)
        return;
    else{
        for(int i=0;i<n/2;i++)
            a[i]+=a[n-i-1];
        n=n/2;
        f(n);
    }
}
int main()
{
    long long head, tail,freq ;
    long int i,k,n,counter=1000;
    for(n=2;n<=N;n*=2)
    {
        if(n>=pow(2.0,20))
            counter=10;
        else if(n>=pow(2.0,15))
            counter=100;
        else if(n>=pow(2.0,10))
            counter=1000;
        for ( i = 0; i < n;i++)
        {
            a[i]=i+1;
        }
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);
        for(k=0;k<counter;k++){
            f(n);                   //µÝ¹éº¯ÊýÊµÏÖ
            sum=a[0];
        }
        QueryPerformanceCounter((LARGE_INTEGER *)&tail) ;
        cout <<(tail-head) * 1000.0 / freq/counter << endl;
    }
    return 0;
 }
