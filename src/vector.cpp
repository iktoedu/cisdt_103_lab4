#include <cstring>
#include <stdexcept>
#include "vector.h"

Vector::Vector(unsigned int n) : n(n)
{
    this->a = new double[this->n];
    memset(this->a, 0, sizeof(double) * this->n);
}

Vector::Vector(unsigned int n, const double *dp) : n(n)
{
    this->a = new double[this->n];
    memcpy(this->a, dp, sizeof(double) * this->n);
}

Vector::Vector(const Vector &src)
{
    this->n = src.n;
    this->a = new double[this->n];
    memcpy(this->a, src.a, sizeof(double) * this->n);
}

Vector::Vector(unsigned int n, const Vector &another) : n(n)
{
    this->a = new double[this->n];
    memset(this->a, 0, sizeof(double) * this->n);

    memcpy(this->a, another.a, sizeof(double) * ((another.n < this->n) ? another.n : this->n));
}

Vector::~Vector()
{
    delete [] this->a;
    this->a = NULL;
}

int Vector::size() const
{
    return this->n;
}

double Vector::operator[](unsigned int index) const
{
    if (index >= this->n) {
        throw std::out_of_range("Out of bounds");
    }

    return this->a[index];
}

double &Vector::operator[](unsigned int index)
{
    if (index >= this->n) {
        throw std::out_of_range("Out of bounds");
    }

    return this->a[index];
}

Vector &Vector::operator=(const Vector &arg)
{
    if (this == &arg) {
        return *this;
    }

    delete [] this->a;
    this->n = arg.n;
    this->a = new double[this->n];
    memcpy(this->a, arg.a, sizeof(double) * this->n);

    return *this;
}

Vector &Vector::operator+=(const Vector &arg)
{
    if (arg.n > this->n) {
        double *new_array = new double[arg.n];
        memset(new_array, 0, sizeof(double) * arg.n);
        memcpy(new_array, this->a, sizeof(double) * this->n);
        delete [] this->a;
        this->a = new_array;
        this->n = arg.n;
    }

    for (unsigned int i = 0; i < arg.n; i++) {
        this->a[i] += arg.a[i];
    }

    return *this;
}

Vector &Vector::operator*=(const double d)
{
    for (unsigned int i = 0; i < this->n; i++) {
        this->a[i] *= d;
    }

    return *this;
}

Vector &Vector::operator-=(const Vector &arg)
{
    Vector t = arg;
    t *= -1;
    (*this) += t;

    return *this;
}
