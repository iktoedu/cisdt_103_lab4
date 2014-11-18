#include "external_operators.h"
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#define INPUT_MODE_WAITING          0
#define INPUT_MODE_INPUT            1
#define INPUT_MODE_COMPLETE         2

#define INPUT_BUFFER_CHAR_LIMIT     255
#define INPUT_BUFFER_DOUBLE_LIMIT   255

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

std::istream &operator>>(std::istream &input, Vector &arg)
{
    unsigned char mode = INPUT_MODE_WAITING;
    char allowedCharacters[12] = {'0','1','2','3','4','5','6','7','8','9','-','.'};
    char buffer[INPUT_BUFFER_CHAR_LIMIT];
    double elements[INPUT_BUFFER_DOUBLE_LIMIT];
    unsigned int elementCount = 0;
    buffer[0] = '\0';

    try {
        while (INPUT_MODE_COMPLETE != mode) {
            char c = input.get();
            char m[2] = {'\0', '\0'};
            m[0] = c;
            // Exclude all spaces
            if (' ' == c) {
                continue;
            }
            if (INPUT_MODE_WAITING == mode) {
                if ('{' != c) {
                    char error[255];
                    sprintf(error, "Excepcted '%c' but '%c' found", '{', c);
                    throw new std::invalid_argument(error);
                }
                mode = INPUT_MODE_INPUT;
            } else {
                if ((',' == c) || ('}' == c)) {
                    double element = atof(buffer);
                    elements[elementCount++] = element;
                    if ('}' == c) {
                        mode = INPUT_MODE_COMPLETE;
                    }
                    // Restart new buffer
                    buffer[0] = '\0';
                } else if (strstr(allowedCharacters, m)) {
                    unsigned int l = strlen(buffer);
                    buffer[l] = c;
                    buffer[l+1] = '\0';
                } else {
                    char error[255];
                    sprintf(error, "Excepcted [%s] but '%c' found", allowedCharacters, c);
                    throw new std::invalid_argument(error);
                }
            }
        }
    }
    catch (std::invalid_argument e) {
        elementCount = 0;
        throw e;
    }

    if (elementCount) {
        arg.mergeWith(Vector(elementCount, elements));
    }

    return input;
}

std::ostream &operator<<(std::ostream &output, const Matrix &arg)
{
    output << "Matrix size: " << arg.nRows() << "x" << arg.nCols() << std::endl;

    for (unsigned int i = 0; i < arg.nRows(); i++) {
        for (unsigned int j = 0; j < arg.nCols(); j++) {
            output << std::setw(5) << arg[i][j];
        }
        output << std::endl;
    }

    return output;
}
