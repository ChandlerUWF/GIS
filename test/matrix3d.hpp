#ifndef MATRIX3D_HPP
#define MATRIX3D_HPP

class Matrix3D {
    private:
        int rows;
        int cols;
        int** matrix;
        int a, b, c, d, e, f, g, h, i;
    public:
        Matrix3D();
        Matrix3D(int a, int b, int c, int d, int e, int f, int g, int h, int i);
        Matrix3D(const Matrix3D& mat);
        ~Matrix3D();
        Matrix3D& operator=(const Matrix3D& rhs);
        int GetValue(int row, int col);
        int Determinant();
};

#endif