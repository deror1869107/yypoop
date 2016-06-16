#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const int& lhs, const int& rhs)
{
	if((lhs & 1) != (rhs & 1)){
		return ((lhs & 1) < (rhs & 1));
	} else {
		return lhs > rhs;
	}
}

void sort(vector<int> &arr){
	std::sort(arr.begin(), arr.end(), cmp);
}

int main(){
    int i,j;	
    vector<int> num;
    while(cin>>j)
        num.push_back(j);

    sort(num);
    std::cout<<"Sorted result: ";
    for(i=0;i<num.size();i++){
        std::cout<<num[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
