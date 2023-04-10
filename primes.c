#include <stdio.h>
#include <math.h>
#include <string.h>

int is_prime(long long );
int GCD(long, long);

int main(int argc, char**argv){
    printf("Hi there\n");
    long n = 600851475143;
    // long n = 3589;
    long N = n;
    long gpf = 0;
    // remove factors of 2
    long d   = 2;
    while (n % d == 0){
        gpf = d;
        n /= d;
    }
    // remove factors of 3
    d = 3;
    while (n % d == 0){
        gpf = d;
        n /= d;
    }
    // remove factors of prime numbers of the form (6n +/- 1)
    long i = 1;
    while(n > 1){
        d = 6*i -1;
        // printf("d = %lld\n", d);
        while (n % d == 0){
            gpf = d;
            n /= d;
        }
        // printf("gpf = %lld\n", gpf);
        d = 6*i +1;
        // printf("d = %lld\n", d);
        while (n % d == 0){
            gpf = d;
            n /= d;
        }
        // printf("gpf = %lld\n", gpf);
        i += 1;
        // a prime factor must be smaller than or equal to the square root
        if (d*d >= n){
            // printf("n == %lld\n", n);
            if (n > 1) gpf = n;
            break;
        }
    }
    printf("The greatest prime factor of %lld, is  %lld", N, gpf);
    return 0;
}

int is_prime(long long num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}
int GCD(long a, long b){
    if(b == 0) return a;
    else return GCD(b, a%b);
}