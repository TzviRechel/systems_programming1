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


int sumOfArmstrong(int n, int power){
    if (n<10){
        return pow1(n, power);
    }
    return pow1(n%10, power)+sumOfArmstrong(n/10, power);
}

int isArmstrong(int n){
    int length = numLength(n);
    int sum = sumOfArmstrong(n, length);
    return(n==sum);
}

int isPalindrome(int num){
    int length = numLength(num);
    if(length == 1){
        return 1;
    }
    if(length == 2){
        if(num%10 == num/10){
            return 1;
        }
        return 0;
    }
    
    int mod = pow1(10, length-1);

    int right = num % 10;
    int left = num/mod;
    if(right != left){
        return 0;
    }
    
    num = num % mod;
    num = num/10;

    return isPalindrome(num);
}