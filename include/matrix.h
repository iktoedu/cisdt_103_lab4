#ifndef MATRIX_H
#define MATRIX_H

#include <cstdio>
#include "vector.h"

class Matrix
{
    public:
        Matrix(unsigned int m, unsigned int n);
        Matrix(unsigned int m, unsigned int n, const double *);
        Matrix(const Matrix &);
        virtual ~Matrix();

        unsigned int nRows() const;
        unsigned int nCols() const;
        Vector column(unsigned int n) const;
        Matrix transpose() const;
        double det() const;

        Vector &operator[](unsigned int) const;
        Vector &operator[](unsigned int);
    protected:
        Matrix vAdditionalMinor(unsigned int, unsigned int) const;
    private:
        Vector **m_rows;
        unsigned int m_rowCount;
};

#endif // MATRIX_H
