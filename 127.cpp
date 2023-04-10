#include<iostream>
#include<bitset>
using namespace std;

int main(){
  char banana = 204;
  char inv_banana = -204;
  int pseudo_inv_banana = 256 - banana;
  cout << "Banana bits: " << bitset<8>(banana) << endl;
  cout << "iBanana bits: " << bitset<8>(inv_banana) << endl;
  cout << "pseudo-iBanana bits: " << bitset<8>(pseudo_inv_banana) << endl;
  return 0;
};