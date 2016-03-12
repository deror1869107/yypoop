#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    map<string, int> menu;
    string str;
    int dollar_value;
    for(int i = 0; i < m; ++i){
        cin >> str >> dollar_value;
        menu[str] = dollar_value;        
    }
    int total;
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

