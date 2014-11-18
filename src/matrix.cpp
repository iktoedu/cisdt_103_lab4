#include <stdexcept>
#include "matrix.h"

Matrix::Matrix(unsigned int m, unsigned int n) : m_rowCount(m)
{
    this->m_rows = new Vector*[m];
    for (unsigned int i = 0; i < m; i++) {
        this->m_rows[i] = new Vector(n);
    }
}

Matrix::Matrix(unsigned int m, unsigned int n, const double *a) : m_rowCount(m)
{
    unsigned int pos = 0;
    this->m_rows = new Vector*[m];
    for (unsigned int i = 0; i < m; i++) {
        this->m_rows[i] = new Vector(n, a + pos);
        pos += n;
    }
}

Matrix::Matrix(const Matrix &src)
{
    this->m_rowCount = src.nCols();
    this->m_rows = new Vector*[this->m_rowCount];
    for (unsigned int i = 0; i < this->m_rowCount; i++) {
        this->m_rows[i] = new Vector(src[i]);
    }
}

Matrix::~Matrix()
{
    for (unsigned int i = 0; i < this->m_rowCount; i++) {
        delete this->m_rows[i];
    }
    delete [] this->m_rows;
}

unsigned int Matrix::nRows() const
{
    return this->m_rowCount;
}

unsigned int Matrix::nCols() const
{
    if (this->m_rowCount > 0) {
        return this->m_rows[0]->size();
    }

    return 0;
}

Vector Matrix::column(unsigned int n) const
{
    Vector column(this->nRows());
    for (unsigned int i = 0; i < this->nRows(); i++)
    {
        column[i] = (*(this))[i][n];
    }

    return column;
}

Matrix Matrix::transpose() const
{
    Matrix transposed(this->nCols(), this->nRows());
    for (unsigned int i = 0; i < this->nRows(); i++) {
        for (unsigned int j = 0; j < this->nCols(); j++) {
            transposed[j][i] = (*(this))[i][j];
        }
    }

    return transposed;
}

double Matrix::det() const
{
    if (this->nCols() != this->nRows()) {
        throw std::invalid_argument("Matrix is not square");
    }

    double det;

    switch (this->nRows()) {
    case 0:
        det = 0;
        break;
    case 1:
        det = (*(this))[0][0];
        break;
    case 2:
        det = (*(this))[0][0]*(*(this))[1][1] - (*(this))[0][1]*(*(this))[1][0];
        break;
    default:
        det = 0;
        unsigned int i = 0;
        for (unsigned int j = 0; j < this->nCols(); j++) {
            double local_det = (*(this))[i][j]*this->vAdditionalMinor(i,j).det();
            if ((i+j) % 2 == 1) {
                local_det *= -1;
            }
            det += local_det;
        }
        break;
    }

    return det;
}

Vector &Matrix::operator[](unsigned int m) const
{
    if (m >= this->m_rowCount) {
        throw std::out_of_range("Out of bounds");
    }

    return *(this->m_rows[m]);
}

Vector &Matrix::operator[](unsigned int m)
{
    if (m >= this->m_rowCount) {
        throw std::out_of_range("Out of bounds");
    }

    return *(this->m_rows[m]);
}

Matrix Matrix::vAdditionalMinor(unsigned int m, unsigned int n) const
{
    Matrix minor(this->nRows() - 1, this->nCols() - 1);

    for (unsigned int i = 0; i < this->nRows(); i++) {
        for (unsigned int j = 0; j < this->nCols(); j++) {
            if ((i == m) || (j == n)) { continue; }
            unsigned int r = i;
            unsigned int c = j;
            if (i > m) { r--; }
            if (j > n) { c--; }
            minor[r][c] = (*(this))[i][j];
        }
    }

    return minor;
}
