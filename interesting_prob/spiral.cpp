#include <iostream>
#include <vector>

std::vector<std::vector<int> > spiral(int n);

std::vector<std::vector<int> > spiral(int n)
{
    std::vector<std::vector<int> > matrix(n, std::vector<int> (n, 0)); // initialize an n x n matrix
    int count = 0, row = 0, row_max = n, col = 0, col_max = n, while_count = 0;
    int next_action = 0; //right = 1, down = 2, left = 3, up = 4
    // matrix[0][0] = 1;
    while (count < n*n && while_count < n*n)
    {
        // move across a single row from left to right
        for(int j = col; j < col_max; j++)
        {
            std::cout << "col_max " << col_max << " " << count << std::endl;
            std::cout << col << std::endl;
            if (matrix[row][j] != 0)
            {
                std::cout << "yay" << std::endl;
                break;
            }
            count++;
            matrix[row][j] = count;
            col = j;
        }
        col_max--;
        next_action = 0;

        // move across a single column from top to bottom
        for(int i = row + 1; i < row_max; i++)
        {
            if (matrix[i][col] != 0)
            {
                break;
            }
            count++;
            matrix[i][col] = count;
            row = i;
        }
        row_max--;
        next_action = 0;

        // move across a single row from right to left
        for(int j = col - 1; j >= 0; j--)
        {
            if (matrix[row][j] != 0)
            {
                break;
            }
            count++;
            matrix[row][j] = count;
            col = j;
        }
        col_max--;
        next_action = 0;

        // move across a single column from bottom to top
        for (int i = row - 1; i >=0; i--)
        {
            if (matrix[i][col] != 0)
            {
                break;
            }
            count++;
            matrix[i][col] = count;
            row = i;
        }
        row_max--;
        std::cout << count << std::endl;
        while_count++;
    }

    // matrix[row][col + 1] = count;

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
