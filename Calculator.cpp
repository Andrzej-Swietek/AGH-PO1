#include "Calculator.h"
#include <iostream>
#include <functional>

Calculator::Calculator()
{
    _value = 0;
}

Calculator& Calculator::operator=(int val)
{
    _value = val;
    return *this;
}

Calculator& Calculator::operator++()
{
    ++_value;
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

Calculator* Calculator::operator->()
{
    return this;
}

int Calculator::operator()()
{
    return _value;
}

int Calculator::operator()(std::function<int(int)> &fun)
{
    return fun(_value);
}

int Calculator::operator()(std::function<int(int,int)> &fun, int val)
{
    return fun(_value, val);
}

int Calculator::operator()(std::function<int(int,int)> &fun, int val1, int val2)
{
    return fun(val1, val2);
}

std::ostream& operator<<(std::ostream& stream, const Calculator& calc)
{
    stream << calc._value;
    return stream;
}