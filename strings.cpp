#include <iostream>

using namespace std;

int main() {
  string text = "text1";
  string text2 = "text2";
  if (text.compare(text2) == 0){
    cout << "They are the same" << endl;
  } else {
    cout << "They are NOT the same" << endl;
  }
}