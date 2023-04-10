# include <stdio.h>

int main(){

    printf("Hi there\n");
    int sum = 0;
    for(int i = 0; i<1000; i++){
        if(i%3 == 0 || i%5 == 0){
            sum += i;
        }
    }
    printf("The sum of all multiples of 3 and 5 below 1000 is %d", sum);
    return 0;
}
