#include <iostream>
#include <vector>

std::vector<std::vector<int> > spiral(int n);

std::vector<std::vector<int> > spiral(int n)
{
    std::vector<std::vector<int> > matrix(n, std::vector<int> (n, 0)); // initialize an n x n matrix
    int count = 1, row = 0, row_max = n, col = 0, col_max = n;
    int action = 1; //right = 1, down = 2, left = 3, up = 4
    while (1)
    {
        if (count > n*n)
        {
            break;
        }
        // move across a single row from left to right
        for(int j = col; j < col_max; j++)
        {
            if (matrix[row][j] != 0)
            {
                break;
            }
            matrix[row][j] = count;
            count++;
            col = j;
        }
        col_max--;

        if (count > n*n)
        {
            break;
        }
        // move across a single column from top to bottom
        for(int i = row + 1; i < row_max; i++)
        {
            if (matrix[i][col] != 0)
            {
                break;
            }
            matrix[i][col] = count;
            count++;
            row = i;
        }
        row_max--;

        if (count > n*n)
        {
            break;
        }
        // move across a single row from right to left
        for(int j = col - 1; j >= 0; j--)
        {
            if (matrix[row][j] != 0)
            {
                break;
            }
            matrix[row][j] = count;
            count++;
            col = j;
        }
        col_max--;

        if (count > n*n)
        {
            break;
        }
        // move across a single column from bottom to top
        for (int i = row - 1; i >=0; i--)
        {
            if (matrix[i][col] != 0)
            {
                break;
            }
            matrix[i][col] = count;
            count++;
            row = i;
        }

    }
    
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
