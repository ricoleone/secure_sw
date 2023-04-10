#include <stdio.h>
#include <math.h>
#include <string.h>

long reverse_long(long);
long XOR(long a, long b);

int main(int argc, char**argv){
    printf("Hi there\n");
    long n = 0;
    long m = 0;
    long p = 0;
    long r = 0;
    long g = 0;

    n = 1234567;
    r = reverse_long(n);
    //reverse the number and XOR with the number if zero, then its a palindrome
    for(int i = 100; i<1000; i++){
        for(int j = 100; j < 1000; j++){
            p = i*j;
            r = reverse_long(p);
            if((r ^ p) == 0){
                //printf("%d is a palidrome of %d * %d\n", p, i, j);
                if( p > g) g = p;
            }
        }
    }
    printf("The greatest palindrome of two three digit numbers is %lld",g);
    return 0;
}
long reverse_long(long n){
    long b = 0; 
    long r = 0;
    while (n !=0){
        r = n % 10;
        b = b * 10 + r;
        n /= 10;
    }
    return b;
}
long XOR(long a, long b){
    return (a | b) & (~a | ~b);
}