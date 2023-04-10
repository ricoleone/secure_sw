#include <stdio.h>
#include <math.h>
#include <string.h>

longisprime(long N);
long ppow(long, long e);

long main(long argc, char**argv){
        printf("running smallest multiple of longegers\n");
        // will use indexes 2 -20 to store greatest number of each prime factor
        long n = 30;
        long N = n + 1;
        long prime_factors[N];
        memset(prime_factors, 0, sizeof(prime_factors));
        long count = 0;
        long max_count = -1;
        long prod  = 1;
        for(long i=2; i<N; i++){
            for(long j = 2; j < N; j++){
                long tmp = j;
                while(tmp % i == 0){
                    count++;
                    tmp /= i;
                }
                if(max_count < count){
                    max_count = count;
                }
                count = 0;
            }
            if(isprime(i)){
                prime_factors[i] = max_count;
            }
            // printf("prime_factors[%d] = %d\n", i, prime_factors[i]);
            max_count = -1;
        }
        for(long i = 2; i < N; i++){
            // printf("ppow(%d, %d) = %d\n", i, prime_factors[i], ppow(i, prime_factors[i]));
            if(isprime(i))
                prod *= ppow(i, prime_factors[i]);
        }
        printf("The smallest number divisible by all integers less than or equal to %d is %lld",n, prod);
        return 0;
}
// determine if a number is prime
long isprime(long N){
        long flag = 1;
        // loop to iterate through 2 to N/2
        for (long i = 2; i <= N / 2; i++) {
            // if N is divisible by i
            // flag is set to 0 (false)
            if (N % i == 0) {
                flag = 0;
                break;
            }
        }
        return flag;
    }
// raise a number to a positive power
long ppow(long b, long e){
        long val = 1;
        while( e > 0) {
            val *= b;
            e--;
        }
        return val;
    }