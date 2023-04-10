#include <iostream>
#include <bitset>
#include <climits>
#include <cmath>
using namespace std;

int main(){
  int banana = 23;
  int num_bits = sizeof(banana)*CHAR_BIT;
  cout << "Banana bits (8-pad): " << bitset<8>(banana) << endl;
  cout << "Num of Banana bits: " << num_bits << endl;
  cout << "Bits ber char: " << CHAR_BIT << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of short: " << sizeof(short) << endl;
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of long: " << sizeof(long) << endl;
  cout << "Size of long long: " << sizeof(long long) << endl;
  cout << "Bits per char: " << sizeof(char)*CHAR_BIT << endl;
  cout << "Bits per short: " << sizeof(short) *CHAR_BIT << endl;
  cout << "Bits per int: " << sizeof(int) *CHAR_BIT << endl;
  cout << "Bits per long: " << sizeof(long) *CHAR_BIT << endl;
  cout << "Bits per long long: " << sizeof(long long) *CHAR_BIT << endl;
  cout << "That is: " << pow(2, sizeof(long long)*CHAR_BIT) << " possible long long values" << endl;
  return 0;
};