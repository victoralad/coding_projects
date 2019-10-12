#include <iostream>
#include <vector>

void printVec(std::vector<int> &vec, int upperBnd);

void bubbleSort(std::vector<int> &vec);

void printVec(std::vector<int> &vec, int upperBnd)
{
    for (int i = 0; i < upperBnd; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void bubbleSort(std::vector<int> &vec)
{
    int temp; bool no_swap;
    while (1)
    {
        no_swap = true;
        for(int i = 1; i < vec.size(); ++i)
        {
            if (vec[i - 1] > vec[i])
            {
                temp = vec[i];
                vec[i] = vec[i - 1];
                vec[i - 1] = temp;
                no_swap = false;
            }
        }
        if (no_swap)
        {
            break;
        }
    }
}

int main()
{
    std::vector<int> vec{5, 4, 6, 2, 3, 8, 7};
    bubbleSort(vec);

    printVec(vec, vec.size());

    return 0;
}