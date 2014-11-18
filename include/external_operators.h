#ifndef EXTERNAL_OPERATORS_H
#define EXTERNAL_OPERATORS_H

#include "vector.h"
#include "matrix.h"
#include <iostream>

double operator*(const Vector &, const Vector &);
Vector operator*(double, const Vector &);
Vector operator*(const Vector &, double);
Vector operator+(const Vector &, const Vector &);
Vector operator-(const Vector &, const Vector &);

std::ostream &operator<<(std::ostream &, const Vector &);
std::istream &operator>>(std::istream &, Vector &);
std::ostream &operator<<(std::ostream &, const Matrix &);

#endif // EXTERNAL_OPERATORS_H
