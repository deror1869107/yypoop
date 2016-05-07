#include "p2.hpp"

int main(){
	Stack<int,0> s;
	for(int i=0;i<10;i++)	
		s.push(i);
	s.dump();
	return 0;
}
