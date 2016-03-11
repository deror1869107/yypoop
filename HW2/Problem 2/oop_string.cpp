#include"oop_string.h"
#include<algorithm>
#include<functional>

namespace oop{
  void reverse( std::string &str){
      reverse(str.begin(), str.end());
  }

  void toUpperCase( std::string &str){
      for(auto it = str.begin(); it != str.end(); ++it){
          if(*it >= 'a' and *it <= 'z'){
                *it += 'A' - 'a';
          }
      }
  }
  
  void trim( std::string &str){
      while(*(str.begin()) == ' '){
          str.erase(str.begin());
      }
      while(*(str.rbegin()) == ' '){
          str.pop_back();
      }
  }
};

