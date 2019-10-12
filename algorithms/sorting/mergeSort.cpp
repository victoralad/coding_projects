#include <iostream>
#include <vector>

void printVec(std::vector<int> &vec, int upperBnd);

void mergeSort(std::vector<int> &vec);

void merge(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right);

void printVec(std::vector<int> &vec, int upperBnd)
{
    for (int i = 0; i < upperBnd; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void mergeSort(std::vector<int> &vec)
{
    if (vec.size() > 1)
    {
        int mid = vec.size()/2;
        std::vector<int> left(mid);
        std::vector<int> right(vec.size() - mid);
        for(int i = 0; i < mid; ++i)
        {
            left[i] = vec[i];
            right[i] = vec[i + mid];
        }
        // check for the last element in case the length of the original vector was odd. (i.e. 7/2 = 3)
        if (right.size() > mid)
        {
            right[right.size() - 1] = vec[vec.size() - 1];
        }
        mergeSort(left);
        mergeSort(right);
        merge(left, right, vec);
    }
}

void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vec)
{
    int left_index = 0, right_index = 0, vec_index = 0;
    while (left_index < left.size() && right_index < right.size())
    {
        if (left[left_index] < right[right_index])
        {
            vec[vec_index] = left[left_index];
            left_index++;
        }
        else
        {
            vec[vec_index] = right[right_index];
            right_index++;
        }
        vec_index++;
    }
    while (left_index < left.size())
    {
        vec[vec_index] = left[left_index];
        left_index++;
        vec_index++;
    }
    while (right_index < right.size())
    {
        vec[vec_index] = right[right_index];
        right_index++;
        vec_index++;
    }
}

int main()
{
    std::vector<int> vec{5, 4, 6, 2, 3, 8, 7};
    mergeSort(vec);

    printVec(vec, vec.size());

    return 0;
}