#include "Calculator.h"
#include <iostream>
#include <functional>

Calculator::Calculator()
{
    _value = 0;
}


Calculator::Calculator(int value)
{
    _value = value;
}


Calculator& Calculator::operator=(int value)
{
    _value = value;
    return *this;
}


Calculator& Calculator::operator++(int)
{
    _value+=1;
    return *this;
}

Calculator& Calculator::operator--()
{
    --_value;
    return *this;
}

int Calculator::operator*(int val)
{
    return _value * val;
}



Calculator operator*(int multiplier, Calculator& obj )
{
    int value = (int)(multiplier * obj._value);
   Calculator tmp(value);
   return tmp;
}


int Calculator::operator()()
{
    return _value;
}

int Calculator::operator()(std::function<int(int)> fun)
{
    return fun(_value);
}


int Calculator::operator()(std::function<int(int,int)> fun, int val) const
{
    int v = fun(_value, val);
    return v;
}




std::ostream& operator<<(std::ostream& stream, const Calculator& calc)
{
    stream << calc._value;
    return stream;
}