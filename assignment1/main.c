#include"NumClass.h"
#include<stdio.h>

int main()
{
    int first;
    int second;
    int temp;
    printf("enter the first number:\n");
    scanf("%d", &first);
    printf("enter the second number:\n");
    scanf("%d", &second);
    if(first>second){
        temp=first;
        first=second;
        second=temp;
    }
    int i;
    
    printf("The Armstrong numbers are: ");
    for(i=first;i<=second;i++){
        if(isArmstrong(i)){
            printf("%d ", i);
        }
    }
    
    printf("\nThe Palindromes are: ");
    for(i=first;i<=second;i++){
        if(isPalindrome(i)){
            printf("%d ", i);
        }
    }
    printf("\nThe Prime numbers are: ");
    for(i=first;i<=second;i++){
        if(isPrime(i)){
            printf("%d ", i);
        }
    }
    printf("\nThe Strong numbers are: ");
    for(i=first;i<=second;i++){
        if(isStrong(i)){
            printf("%d ", i);
        }
    }
    
    printf("\n");
    

    return 0;
}
