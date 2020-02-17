#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <thread>
#include <iomanip>
#include <memory>

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
    std::vector<std::vector<double> >& transpose();             // transpose matrix
    std::vector<std::vector<double> >& operator*(const Matrix &matObj2);              // multiply two matrices together
    Matrix& operator=(const Matrix &matrixObj); // assign matrix to another matrix
    Matrix& operator=(std::vector<std::vector<double> >& newMatrix);
    friend std::ostream& operator<<(std::ostream &osstream, const Matrix &matrixObj); // print out matrix by overloading the << operator
    friend std::ostream& operator<<(std::ostream& oss, std::vector<std::vector<double> >& newMatrix);

private:
    int nRows;
    int nCols;
    std::vector<std::vector<double> > matrix;
    std::vector<std::vector<double> > newMatrix;
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
    matrix.resize(nRows);
    for (int i = 0; i < nRows; ++i)
    {
        matrix[i].resize(nCols);
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
inline std::vector<std::vector<double> >& Matrix::transpose()
{
    newMatrix.resize(nCols);
    for (int j = 0; j < nCols; ++j)
    {
        newMatrix[j].resize(nRows);
        for (int i = 0; i < nRows; ++i)
        {
            newMatrix[j][i] = matrix[i][j];
        }
    }
    return newMatrix;
}

// multiply two matricesmatObj1 and matObj2
inline std::vector<std::vector<double> >& Matrix::operator*(const Matrix &matObj2) 
{

    if (this->nCols != matObj2.nRows)
    {
        std::cout << "Matrix dimensions do not allow for multiplication" << std::endl;
        return newMatrix;
    }
    
    newMatrix.resize(nRows);
    for (int i = 0; i < nRows; ++i)
    {
        newMatrix[i].resize(matObj2.nCols);
        for (int j = 0; j < matObj2.nCols; ++j)
        {
            newMatrix[i][j] = 1;
        }
    }
    return newMatrix;
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

// assign matrix to another matrix
inline Matrix& Matrix::operator=(std::vector<std::vector<double> >& newMatrix)
{

    nRows = newMatrix.size();
    nCols = newMatrix[0].size();
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            // Copy over everything
            matrix[i][j] = newMatrix[i][j];
        }
    }
    // Return
    return *this;
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

// print out matrix by overloading the << operator
inline std::ostream& operator<<(std::ostream& oss, std::vector<std::vector<double> >& newMatrix)
{
    for (int i = 0; i < newMatrix.size(); i++)
    {
        for (int j = 0; j < newMatrix[i].size(); j++)
        {
            oss << std::scientific << std::setw(12) << std::setprecision(3) << newMatrix[i][j]; // add the matrix to oss in the right format
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
