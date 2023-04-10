#include<iostream>
#include<bitset>
using namespace std;

int main(){
  
  unsigned char binary_data = 0b11110010;
  cout << "Binary bits: " << bitset<16>(binary_data) << endl;  
  cout << "Flipped bits: " << bitset<8>(~binary_data) << endl;
  cout << "Left shift bits: " << bitset<16>(binary_data << 3) << endl;
  cout << "Right shift bits: " << bitset<16>(binary_data >> 3) << endl;
  cout << "Bit-wise AND with 00111100: " << bitset<8>(binary_data & 0b00111100) << endl;
  cout << "Bit-wise OR 00111100: " << bitset<8>(binary_data | 0b00111100) << endl;
  cout << "Bit-wise XOR with 00111100: " << bitset<8>(binary_data ^ 0b00111100) << endl;
  return 0;
};