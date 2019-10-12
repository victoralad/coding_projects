/*
    This algorithm sorts a vector based on picking the last element of an array
    and using this last element as a pivot for partitioning the array
*/
#include <iostream>
#include <vector>

void printVec(std::vector<int> &vec, int upperBnd);

void quickSort(std::vector<int> &vec);

void recurse_quickSort(std::vector<int> &vec, int low, int pivot);

void printVec(std::vector<int> &vec, int upperBnd)
{
    for (int i = 0; i < upperBnd; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void quickSort(std::vector<int> &vec)
{
   recurse_quickSort(vec, 0, vec.size() - 1);
}

void recurse_quickSort(std::vector<int> &vec, int low, int pivot)
{
    // printVec(vec, vec.size());
    std::cout << low << " " << pivot << std::endl;
    if (low < pivot)
    {
        for (int i = low; i < pivot; ++i)
        {
            if (vec[i] > vec[pivot])
            {
                int temp;
                temp = vec[i];
                vec[i] = vec[pivot];
                vec[pivot] = temp;
                pivot = i;
            }
        }
        recurse_quickSort(vec, low, pivot - 1);
        recurse_quickSort(vec, pivot + 1, vec.size() - 1);
    }
}

// 5 4 6 2 3 7 8

int main()
{
    std::vector<int> vec{5, 4, 6, 2, 3, 8, 7};
    quickSort(vec);

    printVec(vec, vec.size());

    return 0;
}