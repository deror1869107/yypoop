#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main()
{
    long long int n;
    while(true){
        cin >> n;
        if(cin.eof()){
            break;
        }
        while(cin.peek() == ' '){
            cin.ignore(1, '\n');
        }
        if(cin.fail() || cin.peek() != '\n'){
            cout << "not a number!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cout << hex << n << ' ' << oct << n << endl;
        }
    }
    return 0;
}

