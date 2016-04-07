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
        if(cin.fail() || isalpha(cin.peek())){
            cout << "not a number!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cout << hex << n << ' ' << oct << n << endl;
        }
    }
    return 0;
}

