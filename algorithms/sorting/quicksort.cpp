/*
    This algorithm sorts a vector based on picking the last element of an array
    and using this last element as a pivot for partitioning the array
*/
#include <iostream>
#include <vector>


void printVec(std::vector<int> &vec, int upperBnd);

void quickSort(std::vector<int> &vec);

void recurse_quickSort(std::vector<int> &vec, int start, int end);

int partition(std::vector<int> &vec, int start, int end);

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

void recurse_quickSort(std::vector<int> &vec, int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(vec, start, end);
        recurse_quickSort(vec, start, pIndex - 1);
        recurse_quickSort(vec, pIndex + 1, end);
    }
}

int partition(std::vector<int> &vec, int start, int end) 
{
    // int pivot = vec[end];
    int pIndex = start;
    for (int i = start; i < end; ++i)
    {
        if (vec[i] <= vec[end])
        {
            int temp;
            temp = vec[i];
            vec[i] = vec[pIndex];
            vec[pIndex] = temp;
            pIndex++;
        }
    }
    int temp;
    temp = vec[end];
    vec[end] = vec[pIndex];
    vec[pIndex] = temp;
    return pIndex;
}

int main()
{
    std::vector<int> vec{7, 2, 1, 6, 8, 5, 3, 4};
    quickSort(vec);

    printVec(vec, vec.size());

    return 0;
}