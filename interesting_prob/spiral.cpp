#include <iostream>
#include <vector>

std::vector<std::vector<int> > spiral(int n);

std::vector<std::vector<int> > spiral(int n)
{
    std::vector<std::vector<int> > matrix(n, std::vector<int> (n, 0)); // initialize an n x n matrix

    
   
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
