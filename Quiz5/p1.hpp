const int size=10;
#include <algorithm>
bool cmp(const int&, const int&);
void sort(int arr[]){
	//add here
	std::sort(arr, arr + 10, cmp);
}

bool cmp(const int& lhs, const int& rhs)
{
	if((lhs & 1) != (rhs & 1)){
		return (lhs & 1) < (rhs & 1);
	} else {
		return lhs > rhs;
	}
}

