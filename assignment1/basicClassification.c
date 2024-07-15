#include<stdio.h>
#include"NumClass.h"

int isPrime(int n){
    
    if(n<2){return 0;}
    int i;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
    }

int isStrong(int num){
    int origin=num;
    int factorial[] = {1,1,2,6,24,120,720,5040,40320,362880};

    while(num>0){
        origin -= factorial[num%10];
        if(origin<0){return 0;}
        num = num/10;
    }
    if(origin>0){
        return 0;
    }
    
    return 1;
}