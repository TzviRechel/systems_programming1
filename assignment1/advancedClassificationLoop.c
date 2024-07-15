#include<stdio.h>
#include"NumClass.h"

int pow1(int base, int power){
    int ans=1;
    int i;
    if(power==0){
        return 1;
    }
    for(i=1;i<=power;i++){
        ans=ans*base;
    }
    return ans;
}

int numLength(int num){
    int length = 1;
    while (num >= 10) {
        length++;
        num /= 10;
    }
    return length;
}

/*
assuming the number doesn't include 0's at the beginning
*/
int isPalindrome(int num){
    int pal=0;
    int first_num=num;
    while(num>0){
        pal*=10;
        pal+=num%10;
        num/=10;
    }
    return (pal==first_num);
}


int isArmstrong(int num){
    int origin = num;
    int length = numLength(origin);
    int check = 0;

    while (num>0){
        int base = num%10;
        check += pow1(base, length);
        num = num/10;
    }

    return(check==origin);
}

