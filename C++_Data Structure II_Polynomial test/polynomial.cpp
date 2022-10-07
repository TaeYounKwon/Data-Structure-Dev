#include "polynomial.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cfloat>

using std::istream;
using std::ostream;
using std::string;
using std::stringstream;
using std::fixed;
using std::setprecision;
using std::showpos;

Polynomial::Polynomial(size_t degree) : _degree(degree){
    _coefficients = new float[_degree + 1];
    for (size_t i = 0; i < _degree + 1; i++) {
        _coefficients[i] = 0.0;
    }
}
Polynomial::Polynomial(size_t degree, const float* coefficients): _degree(degree){
    _coefficients = new float[_degree + 1];
    for (size_t i = 0; i < _degree + 1; i++) {
        _coefficients[i] = coefficients[i];
    }
}
Polynomial::Polynomial(const Polynomial& polynomial): _degree(polynomial._degree){
    _coefficients = new float[_degree + 1];
    for (size_t i = 0; i < _degree + 1; i++) {
        _coefficients[i] = polynomial._coefficients[i];
    }
}
Polynomial::~Polynomial() //create destructor
{
    if(_coefficients !=nullptr)
        delete[] _coefficients;
}
const Polynomial Polynomial::Sum(const Polynomial& rhs)const{
    Polynomial sumPoly(_degree+1); //create new data to put some of two polynomials
    for(size_t i=0; i<_degree+1;++i)
    {
        sumPoly._coefficients[i]=_coefficients[i]+rhs._coefficients[i]; //add two polynomials
    }
    return sumPoly;
}
const Polynomial Polynomial::Subtract(const Polynomial& rhs)const{
    Polynomial retVal(*this); //create new data retval to put subtract of two polynomials
    for(size_t i=0; i<_degree+1;++i)
    {
        retVal._coefficients[i]=_coefficients[i]-rhs._coefficients[i]; //subtract two polynomials
    }
    return retVal;
}
const Polynomial Polynomial::Minus()const{
    Polynomial retVal(*this);
    for (size_t i = 0; i < _degree + 1; i++) {
        retVal._coefficients[i] *= -1;
    }
    return retVal;
}
const Polynomial Polynomial::Multiply(const Polynomial& rhs)const{
    Polynomial mulPoly(_degree+rhs._degree+1); //increase the degree by adding two polynomial's degree
    for(size_t i=0;i<_degree+1;i++)                   //x^3 * x^2 = x^(3+2) = x^5
    {
        for(size_t j=0;j<rhs._degree+1;j++)
        {
            mulPoly._degree=_degree+rhs._degree;
            mulPoly._coefficients[i+j]+=_coefficients[i] * rhs._coefficients[j]; //add the same degree's coefficient
        }
    }
    return mulPoly;

}
const Polynomial Polynomial::Divide(const Polynomial& rhs)const{
    Polynomial divPoly(_degree-rhs._degree+1);  // degree decreased by dividing two polynomials.
    for(size_t i=0;i<_degree+1;i++)
    {
        for (size_t j = 0; j < rhs._degree + 1; j++)
        {
            divPoly._degree = _degree - rhs._degree;
            if(rhs._coefficients[j]=0.0f) //value cannot devide by zero, therefore skip if rhs.)coefficients = '0'
                goto skip;
            else
                divPoly._coefficients[i + j] += _coefficients[i] / rhs._coefficients[j]; //add the same degree's coefficient
            skip:
            std::cout<<"";
        }
    }
    return divPoly;
}

const Polynomial Polynomial::Derive()const{
    Polynomial derPoly(_degree-1); // degree decreased by '1' once derive the polynomial
    Polynomial temp(_degree); // temporary array to add needed values
    for( size_t i=0; i<_degree+1;++i)
    {
        temp._coefficients[i]=_coefficients[i]*i; //put coefficients*degree value in temp
    }
    for(size_t i=0;i<_degree;++i)
    {
        derPoly._coefficients[i]=temp._coefficients[i+1]; //put temp[i+1] value into derpoly, the x^0 value will be eliminated
    }
    return derPoly;
}

float Polynomial::Evaluate(float _dataVal) const //get _dataVal float value from user
{
    float _evalVal=0.0f;

    for(size_t i= 0; i<_degree+1;i++)
    {
        float _tmpVal=1.0f;
        for(size_t j=0; j<i; j++)
        {
            _tmpVal=_tmpVal*_dataVal; //multiply dataVal 'each degree times' and then added value to _tmpVal
        }
        _evalVal=_evalVal+(_coefficients[i] * _tmpVal); //then multiply coefficients and _tmpval, then add that value into _evalVal
    }

    return _evalVal;
}

float Polynomial::Integrate(float _start, float _end)const {
    float _integVal = 0.0f; //the final integrated value
    float _integSVal = 0.0f; //value after integrating the start value
    float _integEVal = 0.0f; //value after integrating the end value
    for (size_t i = 0; i < _degree + 1; i++)
    {
        float _tempVal = 1.0f;
        for (size_t j = 0; j <= i; j++)
        {
            _tempVal = _tempVal * _end; //multiply _end value each degree times and then put that value into _tempVal
        }
        _integEVal = _integEVal + (_coefficients[i] * _tempVal/(i+1)); //calculate integrated ending value
    }
    for (size_t i = 0; i < _degree + 1; i++)
    {
        float _tempVal = 1.0f;
        for (size_t j = 0; j <= i; j++)
        {
            _tempVal = _tempVal * _start;//multiply _start value each degree times and then put that value into _tempVal
        }
        _integSVal = _integSVal + (_coefficients[i] * _tempVal/(i+1));//calculate integrated starting value
    }
    _integVal = _integEVal - _integSVal; //calculate the actual integrated value between start and end.

    return _integVal;
}
const Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if (&rhs == this){
        return *this;
    }
    if (_degree != rhs._degree){
        if (_coefficients){
            delete[] _coefficients;
        }
        _degree = rhs._degree;
        _coefficients = new float[_degree + 1];
    }
    for (size_t i = 0; i < _degree + 1; i++) {
        _coefficients[i] = rhs._coefficients[i];
    }
    return *this;
}
bool Polynomial::Equals(const Polynomial& rhs)const{
    if (_degree != rhs._degree){
        return false;
    }
    for (size_t i=0; i < _degree; i++){
        if (abs(_coefficients[i] - rhs._coefficients[i]) > 0.0001){
            return false;
        }
    }
    return true;
}
string Polynomial::ToString()const{
    stringstream ss;
    for (size_t i = _degree; i > 0; i--) {
        ss << showpos << fixed << setprecision(2) << _coefficients[i] << "x^" << i << " ";
    }
    ss << showpos << fixed << setprecision(2) << _coefficients[0];
    return ss.str();
}
ostream& Polynomial::Write(ostream& output)const{
    output << _degree << " ";
    for (size_t i = 0; i < _degree + 1; i++) {
        output << _coefficients[i] << " ";
    }
    return output;
}
istream& Polynomial::Read(istream& input){
    size_t degree;
    input >> degree;
    if (input.fail()){
        return input;
    }
    float* coefficients = new float[degree + 1];
    for (size_t i = 0; i < degree + 1; i++) {
        input >> coefficients[i];
        if (input.fail()){
            delete[] coefficients;
            return input;
        }
    }

    if (degree != _degree){
        if (_coefficients){
            delete[] _coefficients;
        }
        _degree = degree;
        _coefficients = coefficients;
    }else{
        for (size_t i = 0; i < _degree + 1; i++) {
            _coefficients[i] = coefficients[i];
        }
        delete[] coefficients;
    }
    return input;
}
