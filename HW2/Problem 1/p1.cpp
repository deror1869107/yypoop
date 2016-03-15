#include <iostream>
#include <vector>

using namespace std;
      
int main()
{
    int ra, ca, rb, cb;
    cin >> ra >> ca >> cb;
    rb = ca;
    vector<vector<int> > matA(ra);
    vector<vector<int> > matB(rb);
    int now;
    for(int i = 0; i < ra; ++i){
        for(int j = 0; j < ca; ++j){
            cin >> now;
            matA[i].push_back(now);
        }
    }
    for(int i = 0; i < rb; ++i){
        for(int j = 0; j < cb; ++j){
            cin >> now;
            matB[i].push_back(now);
        }
    }
    vector<vector<int> > matAns(ca);
    for(int i = 0; i < ra; ++i){
        for(int j = 0; j < cb; ++j){
            int res = 0;
            for(int k = 0; k < ca; ++k){
                res += matA[i][k] * matB[k][j];
            } 
            matAns[i].push_back(res);
        }
    }
    for(int i = 0; i < ra; ++i){
        for(int j = 0; j < cb; ++j){
            cout << matAns[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

