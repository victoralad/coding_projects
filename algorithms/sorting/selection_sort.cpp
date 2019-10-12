/*
    This algorithm sorts an array based on increasing the lower bound of the array
    and finding the minimum element in the new array. The minimum element is swapped 
    to the first element of the right subarray 
*/
#include <iostream>
#include <vector>

void printVec(std::vector<int> &vec, int upperBnd);

void selection_sort(std::vector<int> &vec);

void printVec(std::vector<int> &vec, int upperBnd)
{
    for (int i = 0; i < upperBnd; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void selection_sort(std::vector<int> &vec)
{
    for (int i = 1; i < vec.size(); ++i)
    {
        int temp, minVal_index = i - 1;
        int minVal = vec[minVal_index]; 
        for (int j = i; j < vec.size(); ++j)
        {
            if (minVal > vec[j])
            {
                minVal = vec[j];
                minVal_index = j;
            }
        }
        temp = vec[i - 1];
        vec[i - 1] = minVal;
        vec[minVal_index] = temp;
    }
}

int main()
{
    std::vector<int> vec{5, 4, 6, 2, 3, 8, 7};
    selection_sort(vec);

    printVec(vec, vec.size());

    return 0;
}