#include <iostream>
#include "BigNum.h"

BigNum::BigNum()
    :size(1), sign(1)
{
}

BigNum::BigNum(int const n)
{
    int t = n;
    sign = 1; //Fix Bug
    size = 0;
    if(t < 0){
        sign = -1;
        t *= -1;
    }
    while(t > 0){
        num[size++] = t % 10;
        t /= 10;
    }
    if(size == 0) size = 1;
}

BigNum::BigNum(std::string const &n)
{
    sign = 1; //Fix Bug
    size_t nonzero = 0;
    if(n.front() == '-'){
        sign = -1;
        nonzero = 1;
    }
    for(;nonzero < n.size(); ++nonzero){
        if(n[nonzero] != '0') break;
    }
    std::string s = n.substr(nonzero);
    for(size_t i = 0; i < s.size(); ++i){
        num[i] = s[s.size() - 1 - i] - '0';
    }
    this->trim();
}

BigNum BigNum::operator+(const BigNum &n) const
{
    BigNum o;
    if(sign == n.sign){
        o.size = std::max(size, n.size);
        o.sign = sign;
        int carry = 0;
        for(int i = 0; i < o.size; ++i){
            o.num[i] = num[i] + n.num[i] + carry;
            if(o.num[i] >= 10){
                o.num[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if(carry) o.num[o.size++] += 1;
        return o;
    } else {
        return *this - (-n);
    }
}

BigNum BigNum::operator-(const BigNum &n) const
{
    BigNum o;
    if(sign == n.sign){
        if(abs(*this) >= abs(n)){
            o.sign = sign; // Bug
            int borrow = 0;
            for(int i = 0; i < size; ++i){
                o.num[i] = num[i] - n.num[i] - borrow;
                if(o.num[i] < 0){
                    o.num[i] += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
            }
            o.trim();
            return o;
        } else return (-n) - (-(*this));
    } else return *this + (-n);
}

BigNum BigNum::operator-() const
{
    if((*this).size == 1 && (*this).num[0] == 0) return *this; //+0 shouldn't change to -0
    BigNum o = *this;
    o.sign *= -1;
    return o;
}

bool BigNum::operator<(const BigNum& n) const
{
    if(sign != n.sign){
        return sign < n.sign;
    }
    if(size != n.size){
        return size < n.size;
    }
    for(int i = size - 1; i >= 0; --i){//Fix Bug
        if(num[i] != n.num[i]){
            return num[i] < n.num[i];
        }
    }
    return false;
}

bool BigNum::operator>=(const BigNum& n) const
{
    return !(*this < n);
}

BigNum abs(const BigNum& n)
{
    BigNum o = n;
    o.sign = 1;
    return o;
}

BigNum BigNum::operator*(const BigNum &n) const
{
    BigNum o;
    o.sign = sign * n.sign;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < n.size; ++j){
            o.num[i + j] += num[i] * n.num[j];
        }
    }
    int carry = 0;
    for(o.size = 0; o.size < MAX_LENGTH; ++o.size){
        o.num[o.size] += carry;
        carry = o.num[o.size] / 10;
        o.num[o.size] %= 10;
    }
    o.trim();
    return o;
}

void BigNum::trim()
{
    size = MAX_LENGTH;
    while(!num[--size] && size > 0){}
    ++size;
    if(size == 1 && num[0] == 0) sign = 1;
}

BigNum& BigNum::operator++()
{
    *this = *this + 1;
    return *this;
}

BigNum BigNum::operator++(int)
{
    BigNum o = *this;
    ++*this;
    return o;
}

std::ostream &operator<<(std::ostream &output, const BigNum &n)
{
    if(n.sign == -1) output << '-';
    for(int i = n.size - 1; i >= 0; --i){
        output << n.num[i];
    }
    return output;
}

std::istream &operator>>(std::istream &input, BigNum &n)
{
    std::string str;
    input >> str;
    n = BigNum(str);
    return input;
}

BigNum operator+(const BigNum &n, const int t)
{
    BigNum o(t);
    return n + o;
}

BigNum operator+(const int t, const BigNum &n)
{
    return n + t;
}

BigNum operator-(const BigNum &n, const int t)
{
    BigNum o(t);
    return n - o;
}

BigNum operator-(const int t, const BigNum &n)
{
    return (-n) - (-t);
}

BigNum operator*(const BigNum &n, const int t)
{
    BigNum o(t);
    return n * o;
}

BigNum operator*(const int t, const BigNum &n)
{
    return n * t;
}
