#include <iostream>
#include <bitset>
#include <climits>
#include <cmath>
using namespace std;

int main(void){
    int banana = -1025;
    unsigned long foobar = 100;
    int num_bits = sizeof(banana)*CHAR_BIT;
    cout << "Banana bits (8-pad): " << bitset<32>(banana) << endl;
    cout << "Num of Banana bits: " << num_bits << endl;
    
    char apple = -1025;
    num_bits = sizeof(apple)*CHAR_BIT;
    cout << "apple bits (8-pad): " << bitset<32>(apple) << endl;
    cout << "Num of apple bits: " << num_bits << endl;
    cout << "Length of unsigned long = " << ULONG_LONG_MAX << endl;

    return 0;
}