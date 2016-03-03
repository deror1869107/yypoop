//
//  p1.cpp
//  
//
//  Created by 宋元堯 on 2016/3/3.
//
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string op;
    stack<int> s;
    int n;
    while(cin >> op){
        if(op[0] == 'i'){
            cin >> n;
            s.push(n);
        } else {
            int num1, num2;
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();
            switch (op[0]) {
                case '+':
                    s.push(num1 + num2);
                    break;
                case '-':
                    s.push(num1 - num2);
                    break;
                case '*':
                    s.push(num1 * num2);
                    break;
                case '/':
                    s.push(num1 / num2);
                    break;
                    
                default:
                    break;
            }
        }
    }
    cout << s.top() << endl;
    return 0;
}
