#include <iostream>
#include "BigNum.h"
using namespace std;

int main(){
    BigNum a("987654321");
    BigNum b("12345678");
    BigNum c;

    cout << a << endl;
    cout << b << endl;
    cout << c <<endl;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;

    cout << a + 123 << endl;
    cout << a - 123 << endl;
    cout << a * 123 << endl;
}

