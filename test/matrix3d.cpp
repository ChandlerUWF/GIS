#include "matrix3d.hpp"

Matrix3D::Matrix3D() {
    this->rows = 3;
    this->cols = 3;
    
    this->matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->d = 0;
    this->e = 0;
    this->f = 0;
    this->g = 0;
    this->h = 0;
    this->i = 0;

    matrix[0][0] = 0;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 0;
    matrix[1][2] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 0;
}

Matrix3D::Matrix3D(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    this->rows = 3;
    this->cols = 3;
    
    this->matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
    this->f = f;
    this->g = g;
    this->h = h;
    this->i = i;

    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[0][2] = c;
    matrix[1][0] = d;
    matrix[1][1] = e;
    matrix[1][2] = f;
    matrix[2][0] = g;
    matrix[2][1] = h;
    matrix[2][2] = i;
}

Matrix3D::Matrix3D(const Matrix3D& mat) {
    rows = mat.rows;
    cols = mat.cols;
    
    a = mat.a;
    b = mat.b;
    c = mat.c;
    d = mat.d;
    e = mat.e;
    f = mat.f;
    g = mat.g;
    h = mat.h;
    i = mat.i;
    
    matrix = new int* [rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[0][2] = c;
    matrix[1][0] = d;
    matrix[1][1] = e;
    matrix[1][2] = f;
    matrix[2][0] = g;
    matrix[2][1] = h;
    matrix[2][2] = i;
}

Matrix3D::~Matrix3D() {
    for(int i = 0; i < 3; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix3D& Matrix3D::operator=(const Matrix3D& rhs) {
    if(&rhs != this) {
        for(int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        rows = rhs.rows;
        cols = rhs.cols;

        a = rhs.a;
        b = rhs.b;
        c = rhs.c;
        d = rhs.d;
        e = rhs.e;
        f = rhs.f;
        g = rhs.g;
        h = rhs.h;
        i = rhs.i;

        matrix = new int* [rows];
        for(int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }

        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[0][2] = c;
        matrix[1][0] = d;
        matrix[1][1] = e;
        matrix[1][2] = f;
        matrix[2][0] = g;
        matrix[2][1] = h;
        matrix[2][2] = i;
    }
    return *this;
}   

int Matrix3D::GetValue(int row, int col) {
    return matrix[row][col];
}

int Matrix3D::Determinant() {
    int determinant;
    determinant = a * ((e * i) - (f * h)) - b * ((d*i) - (f*g)) + c * ((d*h) - (e*g));
    return determinant;
}