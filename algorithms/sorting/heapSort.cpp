#include <iostream>
#include <vector>

void printVec(std::vector<int> &vec, int upperBnd);

void heapSort(std::vector<int> &vec);

void printVec(std::vector<int> &vec, int upperBnd)
{
    for (int i = 0; i < upperBnd; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void heapSort(std::vector<int> &vec)
{
   
}

int main()
{
    std::vector<int> vec{5, 4, 6, 2, 3, 8, 7};
    heapSort(vec);

    printVec(vec, vec.size());

    return 0;
}