#include <iostream>
#include "vector.h"
#include "external_operators.h"
#include "matrix.h"

using namespace std;

int main()
{
    /**
     * First constructor
     */
    Vector vector0 = 4;
    cout << "Vector 0:" << endl << vector0 << endl;

    Vector *vector1 = new Vector(6);
    (*vector1)[0] = 3;
    (*vector1)[2] = 4;
    cout << "Vector 1:" << endl << *vector1 << endl;

    /**
     * Second constructor
     */
    double test_array[5] = {1, 3, 5, 2, 4};
    Vector *vector2 = new Vector(5, test_array);
    cout << "Vector 2:" << endl << *vector2 << endl;

    /**
     * Third constructor
     */
    Vector *vector3 = new Vector(*vector1);
    cout << "Vector 3:" << endl << *vector3 << endl;
    Vector *vector4 = new Vector(*vector2);
    cout << "Vector 4:" << endl << *vector4 << endl;

    /**
     * Fourth constructor
     */
    Vector *vector5 = new Vector(3, *vector2);
    cout << "Vector 5:" << endl << *vector5 << endl;
    Vector *vector6 = new Vector(8, *vector2);
    cout << "Vector 6:" << endl << *vector6 << endl;

    try {
        cout << "Element 2 of Vector 5: " << ((*vector5)[2]) << endl;
    }
    catch (exception e) {
        cout << "Caught exception " << e.what() << endl;
    }

    try {
        cout << "Element 4 of Vector 5: " << ((*vector5)[4]) << endl;
    }
    catch (exception e) {
        cout << "Caught exception " << e.what() << endl;
    }

    /**
     * Operators
     */
    Vector vector7(1);
    cout << "Vector 7:" << endl << vector7 << endl;
    vector7 = (*vector6);
    cout << "Vector 7:" << endl << vector7 << endl;
    vector7 += (*vector1);
    cout << "Vector 7:" << endl << vector7 << endl;
    vector7 = (*vector1);
    cout << "Vector 7:" << endl << vector7 << endl;
    vector7 += (*vector6);
    cout << "Vector 7:" << endl << vector7 << endl;
    vector7 *= 2;
    cout << "Vector 7:" << endl << vector7 << endl;

    cout << "Vector 1 + Vector 2" << endl << (*vector1 + *vector2) << endl;

    cout << "Vector 2 - Vector 1" << endl << (*vector2 - *vector1) << endl;

    cout << "Vector 1 * 2" << endl << (*vector1 * 2) << endl;
    cout << "2 * Vector 1" << endl << (2 * *vector1) << endl;

    cout << "Vector 1 * Vector 2" << endl << (*vector1 * *vector2) << endl;

    cout << "Vector 1 again" << endl << *vector1 << endl;

//    try {
//        cin >> *vector1;
//    }
//    catch (exception e) {
//        cout << "Caught exception" << e.what() << endl;
//    }

    cout << "Vector 1 again" << endl << *vector1 << endl;

    Matrix matrix1(4,4);
    cout << matrix1;

    double sr[9] = {-3,4,1,2,7,-2,5,-5,-6};
    Matrix matrix2(3,3,sr);
    cout << matrix2;
    cout << matrix2.column(1);
    cout << matrix2.transpose();
    cout << "Determinant: " << matrix2.det() << "\nDeterminant of transposed: " << matrix2.transpose().det() << endl;

    return 0;
}
