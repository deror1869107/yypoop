#ifndef __lexical_cast_HPP__
#define __lexical_cast_HPP__

#include <sstream>
#include <typeinfo>

struct bad_lexical_cast: public std::bad_cast {

} ex;

template<typename To, typename From>
To lexical_cast(const From& val)
{
    std::stringstream ss;
    To output;
    ss << std::noskipws << val;
    ss >> std::noskipws >> output;
    if(ss.fail() || !(ss.peek() == EOF)){
        throw ex;
    }
    return output;
}

#endif
