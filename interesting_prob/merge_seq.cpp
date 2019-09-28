// This program merges two sorted arrays
#include <iostream>
#include <vector>

std::vector<int> merge_seq(std::vector<int> &seq1, std::vector<int> &seq2);

// The runtime of this algorithm is O(M + N)
std::vector<int> merge_seq(std::vector<int> &seq1, std::vector<int> &seq2)
{
    int idx1 = 0, idx2 = 0, index = 0;
    std::vector<int> vec(seq1.size() + seq2.size());

    while (idx1 < seq1.size() && idx2 < seq2.size())
    {
        if (seq1[idx1] < seq2[idx2])
        {
            vec[index] = seq1[idx1];
            idx1++;
            index++;
        }
        else
        {
            vec[index] = seq2[idx2];
            idx2++;
            index++;
        }
    }

    if (idx1 == seq1.size())
    {
        for(int i = idx2; i < seq2.size(); ++i)
        {
            vec[i + seq1.size()] = seq2[i];
        }
    }
    else
    {
        for(int i = idx1; i < seq1.size(); ++i)
        {
            vec[i + seq2.size()] = seq1[i];
        } 
    }

    return vec;    
}

int main()
{
    std::vector<int> seq1{1, 3, 6, 7, 9, 10, 14, 18, 19};
    std::vector<int> seq2{2, 3, 5, 8, 9, 11, 14, 15, 16, 17};

    std::vector<int> vec(seq1.size() + seq2.size());

    vec = merge_seq(seq1, seq2);

    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    return 0;
}