#include <iostream>
#include <cmath>
#include "complex.h"

#define PI 3.14159265

ComplexNumber::ComplexNumber()
    :real(0), imag(0)
{

}

ComplexNumber::ComplexNumber(double real, double imag)
    :real(real), imag(imag)
{

}

double ComplexNumber::getReal() const
{
    return real;
}

double ComplexNumber::getImag() const
{
    return imag;
}

void ComplexNumber::setReal(double r)
{
    real = r;
}

void ComplexNumber::setImag(double i)
{
    imag = i;
}

double ComplexNumber::Magnitude() const
{
    return sqrt(real * real + imag * imag);   
}

double ComplexNumber::Phase() const
{
    double phase = atan(imag / real) * 180 / PI;
    if(real >= 0 && imag >= 0){
        return phase;
    } else if(real < 0 && imag >= 0){
        return phase + 180;
    } else if(real < 0 && imag < 0){
        return phase + 180;
    } else {
        return phase + 360;
    }
}

ComplexNumber ComplexNumber::operator!()
{
    ComplexNumber c;
    c.setReal(real);
    c.setImag(imag * -1);
    return c;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& r)
{
    ComplexNumber c;
    c.setReal(real + r.real);
    c.setImag(imag + r.imag);
    return c;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& r)
{
    ComplexNumber c;
    c.setReal(real - r.real);
    c.setImag(imag - r.imag);
    return c;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& r)
{
    ComplexNumber c;
    c.setReal(real * r.real - imag * r.imag);
    c.setImag(real * r.imag + imag * r.real);
    return c;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& r)
{
    ComplexNumber c;
    double dis = r.real * r.real + r.imag * r.imag;
    c.setReal((real * r.real + imag * r.imag) / dis);
    c.setImag((imag * r.real - real * r.imag) / dis);
    return c;
}

void ComplexNumber::show()
{
    std::cout << '(' << real << ',' << imag << ')' << std::endl;
}

void ComplexNumber::polar_coordinate()
{
    std::cout << Magnitude() << " and " << Phase() << " degree" << std::endl;
}

