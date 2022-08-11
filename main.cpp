#include <cstdlib>
#include <iostream>

//#include "fun_ptr.h"

using namespace std;

template <typename ret, typename ...params>
using function_t = ret (*)(params ...args);

template <typename ret, typename obj, typename ...params>
using method_t = ret (obj::*)(params ...args);

void print_helloworld(void)
{
    wcout << L"Hello world" << endl;
}

class anObject final
{
public:
    explicit anObject(void) = default;
    ~anObject(void) = default;

    double multiply(void) noexcept
    {
        return A * B;
    }
    double divide(void) noexcept
    {
        return A / B;
    }
    double addition(void) noexcept
    {
        return A + B;
    }
    double subtraction(void) noexcept
    {
        return A - B;
    }

    void set_values(const double& A, const double& B) noexcept
    {
        this->A = A;
        this->B = B;
    }

private:
    double A, B;
};

int main(int argc, char* argv[])
{
    double A(123.0), B(456.0), C(0.0);
    anObject* myObject(new anObject);
    method_t<void, anObject, const double&, const double&> set_variables(&anObject::set_values);
    method_t<double, anObject> add(&anObject::addition);
    method_t<double, anObject> sub(&anObject::subtraction);
    method_t<double, anObject> mult(&anObject::multiply);
    method_t<double, anObject> div(&anObject::divide);
    function_t<void> print_func = &print_helloworld;
    print_func();
    (myObject->*set_variables)(A, B);
    C = (myObject->*add)();
    wcout << A << L" + " << B << L" = " << C << endl;
    C = (myObject->*sub)();
    wcout << A << L" - " << B << L" = " << C << endl;
    C = (myObject->*mult)();
    wcout << A << L" * " << B << L" = " << C << endl;
    C = (myObject->*div)();
    wcout << A << L" / " << B << L" = " << C << endl;
    delete myObject;
    return 0;
}