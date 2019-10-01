// This program merges two sorted arrays
#include <iostream>
#include <vector>
#include <algorithm>

void merge_seq(std::vector<int> &seq1, std::vector<int> &seq2);

// The runtime of this algorithm is O(M + N)
void merge_seq(std::vector<int> &seq1, std::vector<int> &seq2)
{
    int temp;
    for (int i = 0; i < seq1.size(); ++i)
    {
        for (int j = 0; j < seq2.size(); ++j)
        {
            if (seq1[i] > seq2[j])
            {
                temp = seq1[i];
                seq1[i] = seq2[j];
                seq2[j] = temp;
            }
        }
    }
    // std::sort(seq2.begin(), seq2.end());
    for (int i = 0; i < seq2.size(); ++i)
    {
        for (int j = i; j < seq2.size(); ++j)
        {
            if (seq2[i] > seq2[j])
            {
                temp = seq2[i];
                seq2[i] = seq2[j];
                seq2[j] = temp;
                // i = j;
            }
        }
    }
}

// FT sensor needs to be calibrated with the weight and position of the added gripper, so with the weight of the gripper, it reads zero.

int main()
{
    std::vector<int> seq1{1, 3, 6, 7, 9, 10, 14, 18, 19};
    std::vector<int> seq2{2, 3, 5, 8, 9, 11, 14, 15};

    merge_seq(seq1, seq2);

    for (int i = 0; i < seq1.size(); ++i)
    {
        std::cout << seq1[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < seq2.size(); ++i)
    {
        std::cout << seq2[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
