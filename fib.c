# include <stdio.h>

int fib(int);

int main(){

    printf("Hi there\n");
    int sum = 0;
    int val = 1;
    int i   = 1;
    while(val < 4000000){
        val = fib(i);
        if(val%2 == 0){
            sum += val;
        }
        i++;
    }
    printf("The sum of even fib numbers less than 4 Mil. is %d, i = %d", sum, i);
    return 0;
}

int fib(int n) {
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}