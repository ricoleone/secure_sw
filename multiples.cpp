#include <iostream>

int main(){

    std::cout << "Hi there" << std::endl;
    int sum = 0;
    for(int i = 0; i<1000; i++){
        if(i%3 == 0 || i%5 == 0){
            sum += i;
        }
    }
    std::cout << "The sum of all multiples of 3 and 5 below 1000 is "<< sum << std::endl;
    return 0;
}
