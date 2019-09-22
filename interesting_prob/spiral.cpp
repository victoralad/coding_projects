#include <iostream>
#include <vector>

std::vector<std::vector<int> > spiral(int n);

std::vector<std::vector<int> > spiral(int n)
{
    std::vector<std::vector<int> > matrix(n, std::vector<int> (n, 0)); // initialize an n x n matrix
    int count = 1, row = 0, col = 0, row_max = n, col_max = n;
    while (count < n * n)
    {
        
        if(col < col_max)
        {
            // fix row, move through columns
            matrix[row][col] = count; 
            col++;
            count++;
        }
        else if (row < row_max)
        {
            // fix column, move through rows
            matrix[row][col - 1] = count;
            row++;
            count++;
        }
        else
        {
            row_max--;
            col_max--;
        }
        
    }

    /*
        01 02 03 04
        12 13 14 05
        11 16 15 06
        10 09 08 07

        01 0   0  0
        02 0   0  0
        03 0   0  0
        04 05 06 07
    */
    // for (int row = 0; row < row_max; ++row)
    // {
    //     for (int col = 0; col < col_max; ++col)
    //     {
    //         matrix[row][col] = count;
    //         count++;
    //     }
    // }
    
   
    return matrix;
}

int main()
{
    int n = 3; // input

    std::vector<std::vector<int> > matrix(n, std::vector<int> (n));
    matrix = spiral(n);

    // print matrix values
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
