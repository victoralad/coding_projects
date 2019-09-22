#include <iostream>
#include <deque>

bool one_edit(std::string &word1, std::string word2);

bool one_edit(std::string &word1, std::string word2)
{
    int word1_size = word1.size();
    int word2_size = word2.size();
    if (std::abs(word1_size - word2_size) > 1)
    {
        return false;
    }
    // else if (std::abs(word1_size - word2_size) == 1)
    else
    {
        bool check = true;
        std::deque<char> myDeque1, myDeque2;
        for (int i = 0; i < word1_size; ++i)
        {
            myDeque1.push_back(word1[i]);
        }
        for (int i = 0; i < word2_size; ++i)
        {
            myDeque2.push_back(word2[i]);
        }
        while(!myDeque1.empty() && !myDeque2.empty())
        {
            if (myDeque1.front() == myDeque2.front())
            {
                myDeque1.pop_front();
                myDeque2.pop_front();
            }
            else if (myDeque1.back() == myDeque2.back())
            {
                myDeque1.pop_back();
                myDeque2.pop_back();
            }
            else if (myDeque1.size() > 1 || myDeque2.empty() > 1)
            {
                check = false;
                break;
            }
            
        }
        return check;
    }
    // else
    // {
    //     int count = 0;
    //     for (int i = 0; i < word1_size; ++i)
    //     {
    //         if (word1[i] != word2[i])
    //         {
    //             count++;
    //         }
    //         if (count > 1)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    return true;
}

int main()
{
    std::string word1 = "Jackson";
    std::string word2 = "Jack";
    bool edit_one = one_edit(word1, word2);
    if (edit_one)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}