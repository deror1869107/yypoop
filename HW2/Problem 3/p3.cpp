#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long int m, n;
    cin >> m >> n;
    map<string, long long int> menu;
    string str;
    long long int dollar_value;
    for(int i = 0; i < m; ++i){
        cin >> str >> dollar_value;
        menu[str] = dollar_value;        
    }
    long long int total;
    for(int i = 0; i < n; ++i){
        total = 0;
        cin >> str;
        while(str != "."){
            total += menu[str];
            cin >> str;
        }
        cout << total << endl;
    }
    return 0;
}

