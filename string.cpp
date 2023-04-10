#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Hi there" << endl;
    char foo[32] = "Declaring a string in C++";
    char* ptr = &foo[0];
    cout << "The string: "<< foo << endl;
    cout<< "The string's address: "<< ptr << endl;
  return 0;
}
