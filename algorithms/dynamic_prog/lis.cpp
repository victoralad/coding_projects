#include <iostream>
#include <algorithm>
#include <vector>

int longest_inc_seq(std::vector<int> &vec);

int longest_inc_seq(std::vector<int> &vec)
{
    std::vector<int>longest_seq(vec.size());
    longest_seq[0] = 1;

    if (vec.size() == 1)
    {
        return 1;
    }
    for (int i = 1; i < vec.size(); i++)
    {
        longest_seq[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if ((vec[i] > vec[j]) && (longest_seq[i] < longest_seq[j] + 1))
            {
                longest_seq[i] = 1 + longest_seq[j];
            }
        }
    }
    return *std::max_element(longest_seq.begin(), longest_seq.end());
}

int main()
{
    std::vector<int> vec{3, 10, 2, 1, 20};
    int lis;
    lis = longest_inc_seq(vec);
    std::cout << "The longest increasing sequence is: "<< lis << std::endl;
}