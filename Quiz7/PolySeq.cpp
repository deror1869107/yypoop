#include <iostream>
#include "PolySeq.hpp"

using namespace std;

PolySeq::PolySeq(int n, int arr[])
    :term(n)
{
	ptr = new int[term];
	for(int i = 0; i < term; ++i){
		ptr[i] = arr[i];
	}
}

PolySeq::PolySeq()
    :term(0), ptr(nullptr)
{

}

PolySeq::PolySeq(int n)
    :term(n)
{
    ptr = new int[term];
    for(int i = 0; i < term; ++i){
        ptr[i] = 0;
    }
}

PolySeq PolySeq::Add(const PolySeq& n)
{
    int size = max(term, n.term);
    PolySeq o(size);
    for(int i = 0; i < size; ++i){
        int j = 0;
        if(term - i - 1 >= 0) j += ptr[term - i - 1];
        if(n.term - i - 1 >= 0) j += n.ptr[n.term - i - 1];
        o.ptr[size - i - 1] = j;
    }
    return o;
}

PolySeq PolySeq::Multiply(const PolySeq& n)
{
    PolySeq o(term + n.term - 1);
    for(int i = 0; i < term; ++i){
        for(int j = 0; j < n.term; ++j){
            o.ptr[o.term - i - j - 1] += ptr[term - i - 1] * n.ptr[n.term - j - 1];
        }
    }
    return o;
}

PolySeq PolySeq::Derivative()
{
    PolySeq o(term - 1);
    for(int i = 0; i < term - 1; ++i){
        o.ptr[i] = ptr[i] * (term - i - 1);
    }
    return o;
}

double PolySeq::Integral(int form, int end)
{
    double res = 0;
    double powfrom = 1, powend = 1;
    for(int i = 1; i <= term; ++i){
        powfrom *= form;
        powend *= end;
        res += static_cast<double>(ptr[term - i]) / i * (powend - powfrom);
    }
    return res;
}

void PolySeq::Print()
{
    for(int i = 0; i < term; ++i){
        cout << ptr[i] << ' ';
    }
    cout << endl;
}

PolySeq::~PolySeq()
{
	delete [] ptr;
}

