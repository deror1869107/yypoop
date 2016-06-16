#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    stringstream ss;
    string str;
    vector<int> v1, v2;
    int now;
    getline(cin, str);
    ss << str;
    while(ss >> now){
    	v1.push_back(now);
	}
	ss.clear();
    getline(cin, str);
    ss << str;
	while(ss >> now){
    	v2.push_back(now);
	}
	vector<int> ans(min(v1.size(), v2.size()));
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), ans.begin());
	ans.resize(it - ans.begin());
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i] << " ";
	}
	cout << endl;
    return 0;
}


