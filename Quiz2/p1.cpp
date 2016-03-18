#include<iostream>
#include<stack>
#include<string>
int main()
{
	std::string s;
	std::stack<char> p; 
	while(std::cin>>s)
	{
	     //fill you code  
	     for(int i = 0; i < s.size(); ++i){
	     	p.push(s[i]);
		 }
		 bool ispalindrome = true;
		 for(int i = 0; i < s.size(); ++i){
		 	 if(p.top() != s[i]){
		 	 	ispalindrome = false;
			 }
			 p.pop();
		 }
		 if(!ispalindrome){
		 //if the string is a palindrome 
		 std::cout<<"The string is not a Palindrome"<<std::endl;
         } else {
		 //if the string is not a palindrome
		 std::cout<<"The string is a Palindrome"<<std::endl;
	     }
	}
	
	
	return 0;
}
