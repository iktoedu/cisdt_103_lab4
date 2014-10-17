#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
    public:
        Vector(unsigned int);
        Vector(unsigned int, const double *);
        Vector(const Vector &);
        Vector(unsigned int, const Vector &);
        virtual ~Vector();

        int size() const;

        double operator[](unsigned int) const;
        double &operator[](unsigned int);
        Vector &operator=(const Vector &);
        Vector &operator+=(const Vector &);
        Vector &operator*=(const double);
        Vector &operator-=(const Vector &);
        void mergeWith(const Vector &);

        friend double operator*(const Vector &, const Vector &);
        friend std::ostream &operator<<(std::ostream &, const Vector &);
    private:
        unsigned int n;
        double *a;
};

#endif // VECTOR_H
