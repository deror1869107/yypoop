#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    while(true){
        cin >> n;
        if(cin.eof()){
            break;
        } else if(cin.fail()){
            cout << "not a number!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cout << hex << n << ' ' << oct << n << endl; 
        }
    }
    return 0;
}

