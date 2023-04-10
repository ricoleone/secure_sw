#include<iostream>
#include<bitset>
using namespace std;

int main(){
    unsigned int j = 0;
    char slick[6] = "SLICK";
    while(j < 32){
        for(int m=0; m<5; m++){
            if((j>>m) & 1){
                printf("%c", slick[m]);
            }
        }
        printf(", "); 
        j++;
    }
    return 0;
};