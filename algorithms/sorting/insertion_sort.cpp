/*
    This algorithm sorts a vector in increasing order based on scanning the vector 
    until an decreasing order is encountered, and then the lower element is swapped
    to the left until its right position is found
*/
#include <iostream>
#include <vector>

void printVec(std::vector<int> &vec, int upperBnd);

void insertSort(std::vector<int> &vec);

void printVec(std::vector<int> &vec, int upperBnd)
{
    for (int i = 0; i < upperBnd; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void insertSort(std::vector<int> &vec)
{
    int temp;
    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i - 1] > vec[i])
        {
            temp = vec[i];
            for (int j = i; j > 0; --j)
            {
                if (temp < vec[j - 1])
                {
                    vec[j] = vec[j - 1];
                }
                else
                {
                    vec[j] = temp;
                    break;
                }
            }
            if (temp < vec[0])
            {
                vec[0] = temp;
            }
        }
    }
}

int main()
{
    std::vector<int> vec{5, 4, 6, 2, 3, 8, 7};
    insertSort(vec);

    printVec(vec, vec.size());

    return 0;
}