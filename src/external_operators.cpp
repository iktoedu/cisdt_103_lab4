#include "external_operators.h"
#include <algorithm>

double operator*(const Vector &arg1, const Vector &arg2)
{
    double result = 0;
    for (int i = 0; i < std::max(arg1.size(), arg2.size()); i++) {
        result += ((i < arg1.size() ? arg1[i] : 0)*(i < arg2.size() ? arg2[i] : 0));
    }

    return result;
}

Vector operator*(double arg1, const Vector &arg2)
{
    Vector *t = new Vector(arg2);
    (*t) *= arg1;

    return *t;
}

Vector operator*(const Vector &arg1, double arg2)
{
    Vector *t = new Vector(arg1);
    (*t) *= arg2;

    return *t;
}

Vector operator+(const Vector &arg1, const Vector &arg2)
{
    Vector *t = new Vector(arg1);
    (*t) += arg2;

    return *t;
}

Vector operator-(const Vector &arg1, const Vector &arg2)
{
    Vector *t = new Vector(arg1);
    (*t) -= arg2;

    return *t;
}

std::ostream &operator<<(std::ostream &output, const Vector &arg)
{
    output << "Vector size: " << arg.n << std::endl;
    for (unsigned int i = 0; i < arg.n; i++) {
        output << arg.a[i] << " ";
    }
    output << std::endl;

    return output;
}
