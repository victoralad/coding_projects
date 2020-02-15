#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <thread>
#include <iomanip>

/*
Author: Victor Aladele
Description:
 Implementing matrix class for matrix multiplication and transpose operations
*/

class Matrix
{
public:
    Matrix();                           // constructor
    Matrix(const Matrix &matrixObj);    // copy constructor
    Matrix(std::vector<std::vector<double> > &matrixIn);    // constructor with arguments
    ~Matrix();                          // destructor
    Matrix& transpose(std::vector<std::vector<double> > &matrixIn);             // transpose matrix
    Matrix& operator=(const Matrix &matrixObj); // assign matrix to another matrix
    friend Matrix operator*(const Matrix &matrixObj1, const Matrix &matrixObj2);              // multiply two matrices together
    friend std::ostream& operator<<(std::ostream &osstream, const Matrix &matrixObj); // print out matrix by overloading the << operator
    

private:
    int nRows;
    int nCols;
    std::vector<std::vector<double> > matrix;
};

// default contructor
inline Matrix::Matrix() : nRows(0), nCols(0) 
{
}

// constructor with arguments
inline Matrix::Matrix(std::vector<std::vector<double> > &matrixIn) : matrix(matrixIn), nRows(matrixIn.size()), nCols(matrixIn[0].size())
{
}

// copy constructor
inline Matrix::Matrix(const Matrix &matrixObj)
{
    nRows = matrixObj.nRows;
    nCols = matrixObj.nCols;
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            // Copy over everything
            matrix[i][j] = matrixObj.matrix[i][j];
        }
    }
}

inline Matrix::~Matrix()
{
}

// transpose matrix
inline Matrix& Matrix::transpose(std::vector<std::vector<double> > &matrixIn)
{
    Matrix newMatrix();
    // add stuff here with multi-threading
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            matrix[i][j] = matrixIn[j][i];
        }
    }
    return *this;
}

// assign matrix to another matrix
inline Matrix& Matrix::operator=(const Matrix &matrixObj)
{
    // Check to see if we are trying to assign ourself
    if (this == &matrixObj)
    {
       return *this;
    }
    nRows = matrixObj.nRows;
    nCols = matrixObj.nCols;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            // Copy over everything
            matrix[i][j] = matrixObj.matrix[i][j];
        }
    }
    // Return
    return *this;
}

// multiply two matrices matrixObj1 and matrixObj2
inline Matrix operator*(const Matrix &matrixObj1, const Matrix &matrixObj2) 
{
    // Matrix newMatrix(matrixObj1.nRows, matrixObj2.nCols);
     Matrix newMatrix;
    // add stuff here using multi-threading
    return newMatrix;
}

// print out matrix by overloading the << operator
inline std::ostream& operator<<(std::ostream& oss, const Matrix &matrixObj)
{
    for (int i = 0; i < matrixObj.nRows; i++)
    {
        for (int j = 0; j < matrixObj.nCols; j++)
        {
            oss << std::scientific << std::setw(12) << std::setprecision(3) << matrixObj.matrix[i][j]; // add the matrix to oss in the right format
        }
        oss << std::endl;
    }
    return oss;
}

#endif 

// should I put function members as private or public
// should I use vectors or arrays
// should my functions return a matrix (hence, what type should they be? )
// how do I use threading (use mutex?)
// overload operators

// what is the best ML algorithm to detect a phone in an image
// Does lthread make sense? or should it be lpthread?

// look up if pthread has functions for for loops
// use arrays instead of vectors
// consider return pointers and not the actual object
